#include "llvm/IR/Module.h"
#include "llvm/IR/LLVMContext.h"
#include "llvm/ADT/StringRef.h"
#include "llvm/IR/IRBuilder.h"
#include <map>
#include <string>
#include "../../include/model/Variable.h"
#include "../model/Namespace.h"

#ifndef TYTHON_MODULE_H
#define TYTHON_MODULE_H

class TythonModule : public llvm::Module {

    friend class TythonBuilder;

private:
    llvm::FunctionCallee* number_create_func;
    llvm::FunctionCallee* string_create_func;
    llvm::FunctionCallee* object_is_truthy_func;
    llvm::FunctionCallee* tython_print_func;

    std::map<std::string, llvm::Function*> function_shadow_symbol_table;

private:

    /**
     * @brief Initializes this module
     *
     */
    void initialize();

public:

    TythonModule(llvm::StringRef ModuleID, llvm::LLVMContext& C):
            llvm::Module(ModuleID, C),
            number_create_func(nullptr),
            string_create_func(nullptr),
            tython_print_func(nullptr),
            object_is_truthy_func(nullptr),
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