#ifndef TYTHON_NAMESPACE_H
#define TYTHON_NAMESPACE_H

#include <map>
#include <string>
#include "Variable.h"

class Namespace{

private:
    std::map<std::string, llvm::Value*> variable_shadow_symbol_table;

public:

    Namespace* parent;
    explicit Namespace(Namespace* parent = nullptr) : parent(parent), variable_shadow_symbol_table() {};

    /**
     * Finds a variable by its name, case-insensitive.
     * @param name The name of the variable to find.
     * @return Returns the variable with the specified name, or nullptr if no such variable could be found.
     */
    llvm::Value* findVariable(const std::string& name);

    /**
     * Registers a mapping from a name to a value in this namespace. In other words, creates a variable.
     * @param name The name of the variable.
     * @param value The value associated with the name.
     */
    void registerVariable(const std::string& name, llvm::Value* value);

    [[nodiscard]] bool isGlobal() const;

};


#endif //TYTHON_NAMESPACE_H
