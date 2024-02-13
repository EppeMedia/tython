//
// Created by manzi on 08/02/24.
//

#ifndef TYTHON_UNKOWNSYMBOLEXCEPTION_H
#define TYTHON_UNKOWNSYMBOLEXCEPTION_H

#include "CompileException.h"
#include <string>
#include <utility>

class UnknownSymbolException : public CompileException {

public:
    explicit UnknownSymbolException(std::string cause) : CompileException(std::move(cause)) {};

};

#endif //TYTHON_UNKOWNSYMBOLEXCEPTION_H
