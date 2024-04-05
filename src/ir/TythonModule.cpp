#include "../../include/ir/TythonModule.h"
#include "../../include/exception/CompileException.h"
#include "spdlog/spdlog.h"
#include "llvm/IR/IRBuilder.h"

void TythonModule::initialize() {

    llvm::Type* int32_t = llvm::Type::getInt32Ty(this->getContext());
    llvm::Type* int64_t = llvm::Type::getInt64Ty(this->getContext());
    llvm::Type* double_t = llvm::Type::getDoubleTy(this->getContext());

    llvm::Type* ptr_t = llvm::PointerType::get(this->getContext(), 0);

    // instantiate library functions

    llvm::FunctionType* int_create_type = llvm::FunctionType::get(ptr_t, { int64_t }, false);
    this->int_create_func = new llvm::FunctionCallee();
    *(this->int_create_func) = this->getOrInsertFunction("int_create", int_create_type);

    llvm::FunctionType* float_create_type = llvm::FunctionType::get(ptr_t, { double_t }, false);
    this->float_create_func = new llvm::FunctionCallee();
    *(this->float_create_func) = this->getOrInsertFunction("float_create", float_create_type);

    llvm::FunctionType* string_create_type = llvm::FunctionType::get(ptr_t, { ptr_t, int64_t }, false);
    this->string_create_func = new llvm::FunctionCallee();
    *(this->string_create_func) = this->getOrInsertFunction("string_create", string_create_type);

    llvm::FunctionType* dict_create_type = llvm::FunctionType::get(ptr_t, { int64_t }, false);
    this->dict_create_func = new llvm::FunctionCallee();
    *(this->dict_create_func) = this->getOrInsertFunction("dict_create", dict_create_type);

    llvm::FunctionType* list_create_type = llvm::FunctionType::get(ptr_t, { int64_t }, false); // todo: this and dict_create_types can be just seqalloc_types (and then these class member are no longer needed either)
    this->list_create_func = new llvm::FunctionCallee();
    *(this->list_create_func) = this->getOrInsertFunction("list_create", list_create_type);

    llvm::FunctionType* tuple_create_type = llvm::FunctionType::get(ptr_t, { int64_t }, false); // todo: this and dict_create_types can be just seqalloc_types (and then these class member are no longer needed either)
    this->tuple_create_func = new llvm::FunctionCallee();
    *(this->tuple_create_func) = this->getOrInsertFunction("tuple_create", tuple_create_type);

    llvm::FunctionType* tython_print_type = llvm::FunctionType::get(ptr_t, { ptr_t }, false);
    this->tython_print_func = new llvm::FunctionCallee();
    *(this->tython_print_func) = this->getOrInsertFunction("print", tython_print_type);
    registerProcedure((llvm::Function*)this->tython_print_func->getCallee(), "print"); // user accessible // todo: make a tython wrapper for this in the standard library module

    llvm::FunctionType* tython_range_type = llvm::FunctionType::get(ptr_t, { ptr_t, ptr_t, ptr_t }, false);
    this->tython_range_func = new llvm::FunctionCallee();
    *(this->tython_range_func) = this->getOrInsertFunction("range_create", tython_range_type);
    registerProcedure((llvm::Function*)this->tython_range_func->getCallee(), "range"); // user accessible // todo: make a tython wrapper for this in the standard library module

    llvm::FunctionType* tython_len_type = llvm::FunctionType::get(ptr_t, { ptr_t }, false);
    this->tython_len_func = new llvm::FunctionCallee();
    *(this->tython_len_func) = this->getOrInsertFunction("len", tython_len_type);
    registerProcedure((llvm::Function*)this->tython_len_func->getCallee(), "len"); // user accessible // todo: make a tython wrapper for this in the standard library module

    llvm::FunctionType* tython_slice_type = llvm::FunctionType::get(ptr_t, { ptr_t, ptr_t, ptr_t }, false);
    this->tython_slice_func = new llvm::FunctionCallee();
    *(this->tython_slice_func) = this->getOrInsertFunction("slice", tython_slice_type);
    registerProcedure((llvm::Function*)this->tython_slice_func->getCallee(), "slice"); // user accessible // todo: make a tython wrapper for this in the standard library module

    llvm::FunctionType* object_is_truthy_type = llvm::FunctionType::get(int32_t, {ptr_t }, false);
    this->object_is_truthy_func = new llvm::FunctionCallee();
    *(this->object_is_truthy_func) = this->getOrInsertFunction("object_is_truthy", object_is_truthy_type);

    llvm::FunctionType* resolve_builtin_method_type = llvm::FunctionType::get(ptr_t, {ptr_t, ptr_t }, false);
    this->resolve_builtin_method_func = new llvm::FunctionCallee();
    *(this->resolve_builtin_method_func) = this->getOrInsertFunction("resolve_builtin_method", resolve_builtin_method_type);
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
