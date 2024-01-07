//
// Created by manzi on 19/11/23.
//

#ifndef TYTHON_VARIABLE_H
#define TYTHON_VARIABLE_H

#include <string>
#include <llvm/IR/DerivedTypes.h>
#include "Value.h"

class Variable {

public:

    Variable(std::string& name, llvm::Value* variable, Value* value = nullptr) :
        name(name),
        variable(variable),
        value(value) {};

    std::string name;
    Value* value;
    llvm::Value* variable;

};


#endif //TYTHON_VARIABLE_H
