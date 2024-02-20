#include <iostream>
#include "../include/visitor/SourceFileVisitor.h"
#include "../include/exception/CompileException.h"
#include "../include/utils/Utils.h"
#include "antlr4-runtime.h"
#include <llvm/IR/BasicBlock.h>
#include "../include/ir/TythonModule.h"
#include "llvm/IR/LLVMContext.h"
#include "llvm/IR/LegacyPassManager.h"
#include "llvm/IR/Verifier.h"
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
#include "grammar/generated/TythonLexer.h"
#include "grammar/generated/TythonParser.h"
#include <map>
#include <system_error>
#include <vector>
#include <filesystem>

using namespace std;
using namespace antlr4;
using namespace llvm::sys;

map<string, const std::map<std::string, llvm::Function*>*> object_symbol_table; // { object_name, { function_name, function_value }}

using namespace llvm;

llvm::LLVMContext* llvmContext;
std::string TargetTriple;
TargetMachine* TheTargetMachine;

const DataLayout* datalayout;

#define PRINT_INDENT "-- "

int init_target() {

    llvmContext = new llvm::LLVMContext();

    InitializeAllTargetInfos();
    InitializeAllTargets();
    InitializeAllTargetMCs();
    InitializeAllAsmParsers();
    InitializeAllAsmPrinters();

    TargetTriple = sys::getDefaultTargetTriple();

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
    TheTargetMachine = Target->createTargetMachine(TargetTriple, CPU, Features, opt, RM);

    datalayout = new DataLayout(TheTargetMachine->createDataLayout());

    return 0;
}

std::string build_sourcefile(const configuration_t* config, std::string& path, bool isMain = false) {

    ifstream stream(path);

    if (!stream.is_open()) {
        throw CompileException("File \"" + path + "\" not found");
    }

    std::string objectname = utils::get_objectname(path);

    if (config->verbose) {
        std::cout << "Compiling source \"" << path << "\" to " << (isMain ? "entry " : "") << "module \"" << objectname << "\"" << endl;
    }

    ANTLRInputStream input(stream);
    TythonLexer lexer(&input);
    CommonTokenStream tokens(&lexer);
    TythonParser parser(&tokens);

    TythonParser::ProgramContext* ast = parser.program();

    // init llvm
    auto module = new TythonModule(objectname + "_module", *llvmContext);

    // Run compiler
    auto bb = BasicBlock::Create(*llvmContext);
    TythonBuilder builder(module, bb);

    SourceFileVisitor sourceFileVisitor(module, &builder, object_symbol_table);

    // module (or program) entry point
    auto int32_type = llvm::Type::getInt32Ty(builder.getContext());
    auto entry_function_type = llvm::FunctionType::get(int32_type, false);
    auto entry_function_name = isMain ? "main" : "__module_entry__";
    auto entry_function_linkage = isMain ? llvm::GlobalValue::LinkageTypes::ExternalLinkage : llvm::GlobalValue::LinkageTypes::InternalLinkage;
    auto entry_function = llvm::Function::Create(entry_function_type, entry_function_linkage, entry_function_name, module);
    auto entry_function_bb = llvm::BasicBlock::Create(builder.getContext(), "entry", entry_function);

    // all top-level instructions are inside a main procedure
    builder.SetInsertPoint(entry_function_bb);

    // descend into the source file
    sourceFileVisitor.visitProgram(ast);

    // finish up the main function
    auto zero = llvm::ConstantInt::get(int32_type, 0);
    builder.CreateRet(zero);

    // update compilation unit - symbol table map
    object_symbol_table.insert({ objectname, module->listProcedures() });

    module->setTargetTriple(TargetTriple);
    module->setDataLayout(*datalayout);

    std::string build_dir;

    if (config->build_dir) {
        build_dir = config->build_dir->value_or("build");
    } else {
        build_dir = "build";
    }

    if (sys::fs::exists(build_dir)) {

        if (!sys::fs::is_directory(build_dir)) {

            throw CompileException("Target build path " + build_dir + " is not a directory!");
        }

    } else {

        auto errorcode = sys::fs::create_directories(build_dir);

        if (errorcode) {
            throw CompileException("Failed to write object file: " + errorcode.message());
        }
    }

    const auto object_filename = build_dir + std::filesystem::path::preferred_separator + objectname + ".o";

    std::error_code EC;
    raw_fd_ostream dest(object_filename, EC, sys::fs::OF_None);

    if (EC) {

        errs() << "Could not open file: " << EC.message();

        throw CompileException("Could not open file: " + EC.message());
    }

    legacy::PassManager pass;
    auto FileType = llvm::CodeGenFileType::CGFT_ObjectFile;

    if (TheTargetMachine->addPassesToEmitFile(pass, dest, nullptr, FileType)) {

        errs() << "The selected target cannot emit a file of this type.";

        throw CompileException("The selected target cannot emit a file of this type.");
    }

    // avoid optimizations for debugging
    if (!config->debug) {
        // loop invariant code motion (hoisting code to preheader)
        pass.add(createLICMPass());
        // Promote allocas to registers.
        pass.add(createPromoteMemoryToRegisterPass());
        // Do simple "peephole" optimizations and bit-twiddling optimizations.
        pass.add(createInstructionCombiningPass());
        // Reassociate expressions.
        pass.add(createReassociatePass());
    }

    pass.run(*module);

    if (config->emit_llvm) {

        auto llvm_ir_output_dir = build_dir + std::filesystem::path::preferred_separator + config->emit_llvm.value().value_or("ir");

        if (sys::fs::exists(llvm_ir_output_dir)) {

            if (!sys::fs::is_directory(llvm_ir_output_dir)) {

                throw CompileException("Target path for emitting LLVM IR at " + llvm_ir_output_dir + " is not a directory!");
            }

        } else {

            auto errorcode = sys::fs::create_directories(llvm_ir_output_dir);

            if (errorcode) {

                throw CompileException("Failed to write LLVM IR: " + errorcode.message());
            }
        }

        const auto ir_filename = llvm_ir_output_dir + std::filesystem::path::preferred_separator + objectname + ".ll";

        std::error_code error;
        raw_fd_ostream file(ir_filename, error, sys::fs::OF_None);

        if (error) {

            errs() << "Failed to write LLVM IR: " << error.message();

            throw CompileException("Failed to write LLVM IR: " + error.message());
        }

        module->print(file, nullptr, false, config->debug.has_value());

        file.close();

        if (config->verbose) {
            std::cout << PRINT_INDENT << "Wrote LLVM IR to \"" << ir_filename << "\"" << endl;
        }
    }

    dest.close();

    if (config->verbose) {
        std::cout << PRINT_INDENT << "Wrote \"" << object_filename << "\"" << endl;
    }

    return object_filename;
}

vector<string> build_directory(const configuration_t* config, std::string& path) {

    vector<string> objectFiles;

    // obtain list of .ty files in the specified directory
    if (!std::filesystem::is_directory(path)) {
        throw CompileException("Path " + path + " is not a directory!");
    }

    for (const auto & entry : std::filesystem::directory_iterator(path)) {

        if (entry.is_directory()) {
            // recursively build all subdirectories
            auto subdir = entry.path().string();
            build_directory(config, subdir);
        }

        auto file_path = entry.path().string();

        if (file_path.find(".ty")) { // todo: regex match

            auto objectFile = build_sourcefile(config, file_path);
            objectFiles.push_back(objectFile);
        }
    }

    return objectFiles;
}

int main(int argc, char **argv) {

    const auto configuration = utils::getConfiguration(argc, argv);

    if (configuration.help) {

        cout << MSG_HELP << endl;

        return 0;
    }

    cout << "tython " << TYTHON_VERSION << endl;

    if (!configuration.src_files) {

        cerr << "Error: No source files provided!" << endl;
        cout << MSG_HELP << endl;

        return 1;
    }

    // initialize compilation target
    init_target();

    // build library
    std::string std_dir = "tython_std";
    vector<string> objectFiles = build_directory(&configuration, std_dir);

    // obtain sources
    vector<string> sourceFiles = configuration.src_files.value();

    // identify artefact entry point (if specified)
    optional<optional<string>> entry_source_file_option = configuration.main;
    string entry_source_path;

    if (entry_source_file_option.has_value()){
        // if the flag is present, it must be followed by a path
        if (entry_source_file_option->has_value()) {

            entry_source_path = entry_source_file_option->value();

        } else {
            throw CompileException("The artefact entry point option is missing a source path.");
        }
    }

    // build sources
    for (auto path : sourceFiles) {
        // todo: the '==' check can fail even if the paths resolve to the same inode (i.e. /home/myuser/source.ty != ~/source.ty)...
        auto objectname = build_sourcefile(&configuration, path, path == entry_source_path);
        objectFiles.push_back(objectname);
    }

    if (std::find(sourceFiles.begin(), sourceFiles.end(), entry_source_path) == sourceFiles.end()) {
        // The entry point source file is not present in the specified source files, so it's not built yet. We build it now;
        auto objectname = build_sourcefile(&configuration, entry_source_path, true);
        objectFiles.push_back(objectname);
    }

    std::cout << "Linking objects and building executable..." << endl;

    std::string executable_filename;

    if (configuration.out) {
        executable_filename = configuration.out->value_or("exec");
    } else {
        executable_filename = "exec";
    }

    std::string buildCommand = "clang -o " + executable_filename;

    for (auto &objectFile : objectFiles) {
        buildCommand.append(" " + objectFile);
    }

    if (configuration.link_objects) {

        for (auto &element : configuration.link_objects.value()) {
            buildCommand.append(" " + element);
        }
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
