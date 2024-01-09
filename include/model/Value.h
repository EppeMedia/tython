//
// Created by manzi on 19/11/23.
//

#ifndef TYTHON_VALUE_H
#define TYTHON_VALUE_H

#include <llvm/IR/DerivedTypes.h>

namespace tython {

    enum Type {
        NONE,
        INTEGER,
        FP,
        STRING,
        AGGREGATE,
        UNKNOWN,
    };
}

class Value {

    friend class TythonBuilder;
    friend class SourceFileVisitor;
    class Variable;

public:

    explicit Value(tython::Type type, llvm::Value* content = nullptr) :
        type(type),
        content(content) {}

protected:
    tython::Type type;
    llvm::Value* content;

};

#endif //TYTHON_VALUE_H
