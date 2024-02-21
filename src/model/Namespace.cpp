#include "exception/CompileException.h"
#include "model/Namespace.h"

llvm::Value* Namespace::findVariable(const std::string& name) {

    if (this->variable_shadow_symbol_table.count(name)) {
        return this->variable_shadow_symbol_table.at(name);
    }

    if (this->parent) {
        return this->parent->findVariable(name);
    }

    return nullptr;
}

void Namespace::registerVariable(const std::string& name, llvm::Value* value) {

    if (findVariable(name)) {
        throw CompileException("Attempt to register variable with existing name in scope!");
    }

    this->variable_shadow_symbol_table.insert({ name, value });
}

bool Namespace::isGlobal() const {
    return !this->parent;
}
