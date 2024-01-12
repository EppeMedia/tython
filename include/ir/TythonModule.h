#include "llvm/IR/Module.h"
#include "llvm/IR/LLVMContext.h"
#include "llvm/ADT/StringRef.h"
#include "llvm/IR/IRBuilder.h"
#include <map>
#include <string>
#include "../../include/model/Variable.h"
#include "../model/Scope.h"

#ifndef BCMODULE_H
#define BCMODULE_H

class TythonModule : public llvm::Module {

    friend class TythonBuilder;

private:
    llvm::FunctionCallee* printf_func;
    llvm::FunctionCallee* malloc_func;

    std::map<std::string, Value*> function_shadow_symbol_table;

private:

    /**
     * @brief Initializes this module
     *
     */
    void initialize();

public:

    TythonModule(llvm::StringRef ModuleID, llvm::LLVMContext& C):
            llvm::Module(ModuleID, C),
            printf_func(nullptr),
            malloc_func(nullptr),
            function_shadow_symbol_table() {
        initialize();
    };

    /**
     * Finds a procedure (function) by its name, case-insensitive. Procedures can not be overloaded.
     * @param procedure_name The name of the function to find.
     * @return Returns a pointer to the function with the specified name, or nullptr if no such function could be found.
     */
    Value* findProcedure(const std::string& procedure_name);

    /**
     * Registers a procedure (function) by its name, case-insensitive. Procedures can not be overloaded.
     * @param f The procedure to register.
     * @param return_type The expected return type of the function (may be tython::UNKNOWN).
     * @param procedure_name The name under which to register the procedure.
     */
    void registerProcedure(llvm::Function* f, tython::Type return_type, const std::string& procedure_name);

    const std::map<std::string, Value*> *listProcedures();

};

#endif