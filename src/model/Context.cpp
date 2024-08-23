#include "exception/CompileException.h"
#include "model/Context.h"

llvm::Value* Context::findVariable(const std::string& name) {

    if (this->isLexicalBlock() && this->variable_shadow_symbol_table.count(name)) {
        return this->variable_shadow_symbol_table.at(name);
    }

    if (this->parent) {
        return this->parent->findVariable(name);
    }

    return nullptr;
}

void Context::registerVariable(const std::string& name, llvm::Value* value) {

    if (!this->isLexicalBlock()) {
        throw CompileException("Attempt to register variable in non-lexical context!");
    }

    if (findVariable(name)) {
        throw CompileException("Attempt to register variable with existing name in scope!");
    }

    this->variable_shadow_symbol_table.insert({ name, value });
}

unsigned int Context::getFlags() const {
    return this->flags;
}

bool Context::isGlobal() const {
    return !this->parent;
}

bool Context::isLoop() const {
    return this->flags & TYTHON_CONTEXT_FLAG_LOOP;
}

Context* Context::getEnclosingLoop() {

    if (this->isGlobal()) {
        return nullptr;
    }

    if (this->isLoop()) {
        return this;
    }

    return this->parent->getEnclosingLoop();
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

bool Context::isFunction() const {
    return this->flags & TYTHON_CONTEXT_FLAG_FUNCTION;
}

bool Context::isAssign() const {
    return this->flags & TYTHON_CONTEXT_FLAG_ASSIGN;
}
