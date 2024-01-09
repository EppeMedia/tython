//
// Created by bruh on 3-10-22.
//

#ifndef CROSSOVER_COMPILEEXCEPTION_H
#define CROSSOVER_COMPILEEXCEPTION_H

#include <stdexcept>

class CompileException : public std::logic_error
{
public:
    CompileException(std::string cause) : std::logic_error(cause) { };
};


#endif //CROSSOVER_COMPILEEXCEPTION_H
