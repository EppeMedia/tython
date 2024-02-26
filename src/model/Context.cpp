#include "exception/CompileException.h"
#include "model/Context.h"

llvm::Value* Context::findVariable(const std::string& name) {

    if (this->variable_shadow_symbol_table.count(name)) {
        return this->variable_shadow_symbol_table.at(name);
    }

    if (this->parent) {
        return this->parent->findVariable(name);
    }

    return nullptr;
}

void Context::registerVariable(const std::string& name, llvm::Value* value) {

    if (findVariable(name)) {
        throw CompileException("Attempt to register variable with existing name in scope!");
    }

    this->variable_shadow_symbol_table.insert({ name, value });
}

bool Context::isGlobal() const {
    return !this->parent;
}

bool Context::isLoop() const {
    return this->flags & TYTHON_CONTEXT_FLAG_LOOP;
}

bool Context::isLexicalBlock() const {
    return this->flags & TYTHON_CONTEXT_FLAG_LEX_BLOCK;
}

void Context::setComplete() {
    this->flags = this->flags | TYTHON_CONTEXT_FLAG_COMPLETE;
}

bool Context::isComplete() const {
    return this->flags & TYTHON_CONTEXT_FLAG_COMPLETE;
}
