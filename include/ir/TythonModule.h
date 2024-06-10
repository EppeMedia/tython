#include "llvm/IR/Module.h"
#include "llvm/IR/LLVMContext.h"
#include "llvm/ADT/StringRef.h"
#include "llvm/IR/IRBuilder.h"
#include <map>
#include <string>
#include "../model/Context.h"

#ifndef TYTHON_MODULE_H
#define TYTHON_MODULE_H

class TythonModule : public llvm::Module {

    friend class TythonBuilder;
    friend class SourceFileVisitor;

private:
    llvm::StructType* specialization_type;

    llvm::FunctionCallee* float_create_func;
    llvm::FunctionCallee* int_create_func;
    llvm::FunctionCallee* string_create_func;
    llvm::FunctionCallee* dict_create_func;
    llvm::FunctionCallee* list_create_func;
    llvm::FunctionCallee* tuple_create_func;

    // basicland
    llvm::FunctionCallee* object_is_truthy_func;
    llvm::FunctionCallee* resolve_builtin_method_func;
    llvm::FunctionCallee* object_to_primitive;

    // API
    llvm::FunctionCallee* tython_throw_type_error_func;
    llvm::FunctionCallee* tython_print_func;
    llvm::FunctionCallee* tython_ewout_func;
    llvm::FunctionCallee* tython_range_func;
    llvm::FunctionCallee* tython__tuple__func;
    llvm::FunctionCallee* tython__list__func;
    llvm::FunctionCallee* tython__dict__func;
    llvm::FunctionCallee* tython__set__func;
    llvm::FunctionCallee* tython_len_func;
    llvm::FunctionCallee* tython_slice_func;

    std::map<std::string, llvm::Function*> function_shadow_symbol_table;

    /**
     * @brief Initializes this module
     *
     */
    void initialize();

public:

    TythonModule(llvm::StringRef ModuleID, llvm::LLVMContext& C):
            llvm::Module(ModuleID, C),
            specialization_type(nullptr),
            float_create_func(nullptr),
            int_create_func(nullptr),
            string_create_func(nullptr),
            dict_create_func(nullptr),
            list_create_func(nullptr),
            tython_throw_type_error_func(nullptr),
            tython_print_func(nullptr),
            tython_ewout_func(nullptr),
            tython_range_func(nullptr),
            tython__tuple__func(nullptr),
            tython__list__func(nullptr),
            tython__dict__func(nullptr),
            tython__set__func(nullptr),
            tython_len_func(nullptr),
            tython_slice_func(nullptr),
            tuple_create_func(nullptr),
            object_is_truthy_func(nullptr),
            resolve_builtin_method_func(nullptr),
            object_to_primitive(nullptr),
            function_shadow_symbol_table() {
        initialize();
    };

    /**
     * Finds a procedure (function) by its name, case-insensitive. Procedures can not be overloaded.
     * @param procedure_name The name of the function to find.
     * @return Returns a pointer to the function with the specified name, or nullptr if no such function could be found.
     */
    llvm::Function* findProcedure(const std::string& procedure_name);

    /**
     * Registers a procedure (function) by its name, case-insensitive. Procedures can not be overloaded.
     * @param f The procedure to register.
     * @param return_type The expected return type of the function (may be tython::UNKNOWN).
     * @param procedure_name The name under which to register the procedure.
     */
    void registerProcedure(llvm::Function* f, const std::string& procedure_name);

    /**
     * Lists the procedures in the shadow procedure map.
     * @return Returns copy of the procedures in the shadow procedure map.
     */
    std::map<std::string, llvm::Function*>* listProcedures();

};

#endif // TYTHON_MODULE_H