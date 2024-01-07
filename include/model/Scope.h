#ifndef TYTHON_SCOPE_H
#define TYTHON_SCOPE_H

#include <map>
#include <string>
#include "Variable.h"

class Scope {

private:
    std::map<std::string, Variable*> variable_shadow_symbol_table;

public:

    Scope* parent;
    explicit Scope(Scope* parent = nullptr) : parent(parent), variable_shadow_symbol_table() {};

    /**
     * Finds a data entry (record or field) by its name, case-insensitive.
     * @param name The name of the data entry to find.
     * @return Returns the data entry with the specified name, or nullptr if no such data entry could be found.
     */
    Variable* findDataEntry(const std::string& name);

    void registerDataEntry(Variable *dataEntry);

//    ~Scope() {
//        for (auto & it : variable_shadow_symbol_table) {
//            delete it.second;
//        }
//    }

};


#endif //TYTHON_SCOPE_H
