//
// Created by bruh on 22-9-22.
//

#ifndef CROSSOVER_NOTIMPLEMENTED_H
#define CROSSOVER_NOTIMPLEMENTED_H

#include <stdexcept>

class NotImplemented : public std::logic_error
{
public:
    NotImplemented(std::string cause) : std::logic_error(cause) { };
};

#endif //CROSSOVER_NOTIMPLEMENTED_H
