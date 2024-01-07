#include "../../include/ir/TythonModule.h"
#include "../../include/model/Variable.h"
#include "../../include/exception/CompileException.h"
#include "spdlog/spdlog.h"
#include "llvm/IR/IRBuilder.h"
#include "../../include/model/Scope.h"

void TythonModule::initialize() {

    llvm::Type* void_t = llvm::Type::getVoidTy(this->getContext());
    llvm::Type* voidptr_t = llvm::PointerType::get(void_t, 0);
    llvm::Type* int8ptr_t = llvm::Type::getInt8PtrTy(this->getContext());
    llvm::Type* int32_t = llvm::Type::getInt32Ty(this->getContext());

    // instantiate C functions
    llvm::FunctionType* printf_type = llvm::FunctionType::get(int32_t, { int8ptr_t }, true);
    this->printf_func = new llvm::FunctionCallee();
    *(this->printf_func) = this->getOrInsertFunction("printf", printf_type);

    llvm::FunctionType* malloc_type = llvm::FunctionType::get(voidptr_t, { int32_t }, false);
    this->malloc_func = new llvm::FunctionCallee();
    *(this->malloc_func) = this->getOrInsertFunction("malloc", malloc_type);

    registerProcedure((llvm::Function*)this->printf_func->getCallee(), "printf");
    registerProcedure((llvm::Function*)this->printf_func->getCallee(), "malloc");
}

llvm::Function* TythonModule::findProcedure(const std::string& _procedure_name) {

    std::string procedure_name = std::string(_procedure_name);

    // procedure names are lower case. Lookup is case-insensitive.
    std::transform(procedure_name.begin(), procedure_name.end(), procedure_name.begin(),
                   [](unsigned char c){ return std::tolower(c); });

    if (function_shadow_symbol_table.count(procedure_name)) {
        return function_shadow_symbol_table.at(procedure_name);
    }

    return nullptr;
}

void TythonModule::registerProcedure(llvm::Function* f, const std::string& _procedure_name) {

    std::string procedure_name = std::string(_procedure_name);

    // procedure names are lower case. Lookup is case-insensitive.
    std::transform(procedure_name.begin(), procedure_name.end(), procedure_name.begin(),
                   [](unsigned char c){ return std::tolower(c); });

    if (findProcedure(procedure_name)) {
        throw CompileException("Illegal redefinition of procedure \"" + _procedure_name + "\".");
    }

    function_shadow_symbol_table.insert({ procedure_name, f });
}
