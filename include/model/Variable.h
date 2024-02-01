//
// Created by manzi on 19/11/23.
//

#ifndef TYTHON_VARIABLE_H
#define TYTHON_VARIABLE_H

#include <string>
#include <map>
#include <llvm/IR/Value.h>

/**
 * This is actually just a namespace entry (a name / variable pair).
 */
class Variable : public std::pair<std::string, llvm::Value*> {

public:

    Variable(std::string& name, llvm::Value* llvm_value) :
            name(name),
            llvm_value(llvm_value){};

    std::string name;
    llvm::Value* llvm_value;

};


#endif //TYTHON_VARIABLE_H
