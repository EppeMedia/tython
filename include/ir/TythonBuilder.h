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
    llvm::Value* getContent(Variable* dataEntry);
    llvm::Value* getContent(Value* value);
    llvm::Value* getValueContent(Variable* dataEntry);

    Value* CreateValue(tython::Type type, llvm::Value* content);
    Variable* CreateVariable(std::string& name);

    llvm::Value* CreateMalloc(llvm::Type* type, unsigned int amount = 1);

    llvm::Value* CreateToString(Value* value);
    llvm::Value* CreatePrintF(Value* value);

    ~TythonBuilder() {
//        delete valueStructType;
    }

};

#endif //CROSSOVER_BCBUILDER_H
