//
// Created by manta on 11/10/22.
//

#ifndef CROSSOVER_BCBUILDER_H
#define CROSSOVER_BCBUILDER_H

#include <llvm/IR/IRBuilder.h>
#include "TythonModule.h"
#include "../model/Value.h"
#include "../model/Scope.h"
#include <string>

class TythonBuilder : public llvm::IRBuilder<> {

    friend class SourceFileVisitor;

private:
    llvm::StructType* variableStructType;

    void init();
    void initFirstClassTypes();
    void initBuiltinFunctions();

    Scope* nestScope();
    Scope* popScope();

protected:
    TythonModule* module;
    std::map<tython::Type, llvm::StructType*> typeMap;
    Scope* current_scope;

public:
    TythonBuilder(TythonModule* module, llvm::BasicBlock* bb) : llvm::IRBuilder<>(bb), module(module), variableStructType(nullptr) {
        init();
    };

    llvm::Type* getLLVMType(tython::Type type);
    llvm::StructType* getValueStructType(tython::Type type);
    llvm::Value* CreateGetValuePtr(Variable* dataEntry);
    llvm::Value* CreateGetContent(Value* value);

    /**
     * Generates code for obtaining a variable's current type enumerator
     * @param variable The variable for which to generate the code.
     * @return Returns a handle on the first-class integer value (i8) of the variable's current value.
     */
    llvm::Value* CreateGetType(Variable* variable);
    llvm::Value* CreateGetType(Value* value);

    Value* CreateValue(tython::Type type, llvm::Value* content, bool forceHeap = false);
    Variable* CreateVariable(std::string& name);

    llvm::Value* CreateMalloc(llvm::Type* type, unsigned int amount = 1);

    llvm::Value* CreateToString(Value* value);
    llvm::Value* CreatePrintF(Value* value);

    ~TythonBuilder() {
//        delete valueStructType;
    }

};

#endif //CROSSOVER_BCBUILDER_H
