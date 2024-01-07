#include <iostream>
#include "include/visitor/SourceFileVisitor.h"
#include "include/exception/CompileException.h"
#include "include/utils/Utils.h"
#include "antlr4-runtime.h"
#include <llvm/IR/BasicBlock.h>
#include "include/ir/TythonModule.h"
#include "llvm/IR/LLVMContext.h"
#include "llvm/IR/Function.h"
#include "llvm/IR/LegacyPassManager.h"
#include "llvm/MC/TargetRegistry.h"
#include "llvm/Support/FileSystem.h"
#include "llvm/Support/Host.h"
#include "llvm/Support/TargetSelect.h"
#include "llvm/Support/raw_ostream.h"
#include "llvm/Target/TargetMachine.h"
#include "llvm/Target/TargetOptions.h"
#include "llvm/Transforms/InstCombine/InstCombine.h"
#include "llvm/Transforms/Scalar.h"
#include "llvm/Transforms/Utils.h"
#include "llvm/ADT/Optional.h"
#include "llvm/IR/DerivedTypes.h"
#include "llvm/IR/Type.h"
#include "include/visitor/SourceFileVisitor.h"
#include "include/parser/TythonLexer.h"
#include "include/parser/TythonParser.h"
#include <map>
#include <system_error>
#include <vector>
#include "config.h"
#include "include/ir/TythonBuilder.h"

using namespace std;
using namespace antlr4;
using namespace llvm;
using namespace llvm::sys;

int main(int argc, char **argv) {

    const auto configuration = utils::getConfiguration(argc, argv);

    if (configuration.help) {
        cout << MSG_HELP << endl;
        return 0;
    }

    cout << "tython " << TYTHON_VERSION << endl;

    vector<string> sourceFiles = configuration.src_files;

    ifstream stream;

    stream.open(sourceFiles[0]);

    if (!stream.is_open()) {
        throw CompileException("File \"" + sourceFiles[0] + "\" not found");
    }

    std::cout << "Compiling first stage..." << std::endl;

    ANTLRInputStream input(stream);
    TythonLexer lexer(&input);
    CommonTokenStream tokens(&lexer);
    TythonParser parser(&tokens);

    TythonParser::ProgramContext* ast = parser.program();

    // init  llvm
    auto llvmContext = new llvm::LLVMContext();
    auto module = new TythonModule("module", *llvmContext);

    llvm::FunctionType* FT = llvm::FunctionType::get(llvm::Type::getVoidTy(*llvmContext), false);
    llvm::Function* mainFunction = llvm::Function::Create(FT, llvm::Function::CommonLinkage, "main", module);

    // Run compiler
    llvm::BasicBlock* block = llvm::BasicBlock::Create(*llvmContext, "entry", mainFunction);

    TythonBuilder builder(module, block);

    SourceFileVisitor sourceFileVisitor(module, &builder);
    sourceFileVisitor.visitProgram(ast);

    builder.CreateRetVoid();

    // The following code allows us to compile the IR into C object files

    InitializeAllTargetInfos();
    InitializeAllTargets();
    InitializeAllTargetMCs();
    InitializeAllAsmParsers();
    InitializeAllAsmPrinters();

    auto TargetTriple = sys::getDefaultTargetTriple();
    module->setTargetTriple(TargetTriple);

    std::string Error;
    auto Target = TargetRegistry::lookupTarget(TargetTriple, Error);

    // Print an error and exit if we couldn't find the requested target.
    // This generally occurs if we've forgotten to initialise the
    // TargetRegistry or we have a bogus target triple.
    if (!Target) {
        errs() << Error;
        return 1;
    }
    auto CPU = "generic";
    auto Features = "";

    TargetOptions opt;
    auto RM = Optional<Reloc::Model>(Reloc::PIC_);
    auto TheTargetMachine = Target->createTargetMachine(TargetTriple, CPU, Features, opt, RM);

    auto datalayout = TheTargetMachine->createDataLayout();
    module->setDataLayout(datalayout);

    auto object_filename = "tython.o";
    std::error_code EC;
    raw_fd_ostream dest(object_filename, EC, sys::fs::OF_None);

    if (EC) {
        errs() << "Could not open file: " << EC.message();
        return 1;
    }

    legacy::PassManager pass;
    auto FileType = llvm::CodeGenFileType::CGFT_ObjectFile;

    if (TheTargetMachine->addPassesToEmitFile(pass, dest, nullptr, FileType)) {
        errs() << "TheTargetMachine can't emit a file of this type";
        return 1;
    }

    // avoid optimizations for debugging
    if (!configuration.debug) {
        // loop invariant code motion (hoisting code to preheader)
        pass.add(createLICMPass());
        // Promote allocas to registers.
        pass.add(createPromoteMemoryToRegisterPass());
        // Do simple "peephole" optimizations and bit-twiddling optimizations.
        pass.add(createInstructionCombiningPass());
        // Reassociate expressions.
        pass.add(createReassociatePass());
    }

    std::cout << "Compiling second stage..." << std::endl;

    pass.run(*module);

    if (!configuration.emit_llvm.empty()) {

        std::error_code error;
        raw_fd_ostream file(configuration.emit_llvm, error, sys::fs::OF_None);

        if (error) {

            errs() << "Failed to write LLVM IR: " << error.message();

            return error.value();
        }

        module->print(file, nullptr, false, configuration.debug);

        file.close();

        std::cout << "Wrote LLVM IR to " << configuration.emit_llvm << std::endl;
    }

    dest.close();

    if (configuration.verbose) {
        std::cout << "Wrote " << object_filename << "\n";
    }

    std::cout << "Linking objects and building executable..." << endl;

    std::string executable_filename;

    if (!configuration.out.empty()) {
        executable_filename = configuration.out;
    } else {
        executable_filename = "exec";
    }

    std::string buildCommand = "clang -o " + executable_filename + " " + object_filename;

    for (auto &element : configuration.link_objects) {
        buildCommand.append(" ");
        buildCommand.append(element);
    }

    if (configuration.verbose) {
        std::cout << buildCommand << std::endl;
    }

    auto result = utils::exec(buildCommand);

    if (configuration.verbose) {
        std::cout << "Linking done." << std::endl;
    }

    std::cout << "Compilation successful. Wrote executable to file " << executable_filename << std::endl;

    return 0;
}
