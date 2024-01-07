#include "../../include/exception/CompileException.h"
#include "../../include/model/Scope.h"

Variable* Scope::findDataEntry(const std::string& name) {

    if (this->variable_shadow_symbol_table.count(name)) {
        return this->variable_shadow_symbol_table.at(name);
    }

    if (this->parent) {
        return this->parent->findDataEntry(name);
    }

    return nullptr;
}

void Scope::registerDataEntry(Variable *dataEntry) {

    if (findDataEntry(dataEntry->name)) {
        throw CompileException("Attempt to register variable with existing name in scope!");
    }

    this->variable_shadow_symbol_table.insert({dataEntry->name, dataEntry });
}
