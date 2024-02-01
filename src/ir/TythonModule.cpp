#include "../../include/ir/TythonModule.h"
#include "../../include/model/Variable.h"
#include "../../include/exception/CompileException.h"
#include "spdlog/spdlog.h"
#include "llvm/IR/IRBuilder.h"
#include "../../include/model/Namespace.h"

void TythonModule::initialize() {

    llvm::Type* void_t = llvm::Type::getVoidTy(this->getContext());
    llvm::Type* voidptr_t = llvm::PointerType::get(void_t, 0);
    llvm::Type* int32_t = llvm::Type::getInt32Ty(this->getContext());
    llvm::Type* int64_t = llvm::Type::getInt64Ty(this->getContext());
    llvm::Type* int8ptr_t = llvm::Type::getInt8PtrTy(this->getContext());

    llvm::Type* ptr_t = llvm::PointerType::get(this->getContext(), 0);

    // instantiate library functions

    llvm::FunctionType* number_create_type = llvm::FunctionType::get(ptr_t, { int64_t }, false);
    this->number_create_func = new llvm::FunctionCallee();
    *(this->number_create_func) = this->getOrInsertFunction("float_create", number_create_type);

    llvm::FunctionType* string_create_type = llvm::FunctionType::get(ptr_t, { ptr_t, int64_t }, false);
    this->string_create_func = new llvm::FunctionCallee();
    *(this->string_create_func) = this->getOrInsertFunction("string_create", string_create_type);

    llvm::FunctionType* tython_print_type = llvm::FunctionType::get(ptr_t, { ptr_t }, false);
    this->tython_print_func = new llvm::FunctionCallee();
    *(this->tython_print_func) = this->getOrInsertFunction("print", tython_print_type);
    registerProcedure((llvm::Function*)this->tython_print_func->getCallee(), "print"); // user accesable // todo: make a tython wrapper for this in the standard library module

    llvm::FunctionType* object_is_truthy_type = llvm::FunctionType::get(int32_t, {ptr_t }, true);
    this->object_is_truthy_func = new llvm::FunctionCallee();
    *(this->object_is_truthy_func) = this->getOrInsertFunction("object_is_truthy", object_is_truthy_type);
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

std::map<std::string, llvm::Function*>* TythonModule::listProcedures() {
    return new std::map(this->function_shadow_symbol_table);
}
