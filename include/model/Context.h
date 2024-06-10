#ifndef TYTHON_CONTEXT_H
#define TYTHON_CONTEXT_H

#include <map>
#include <string>
#include <llvm/IR/Value.h>

#define TYTHON_CONTEXT_FLAG_LOOP        (0x1U)  // set if this is the top-level context of a loop
#define TYTHON_CONTEXT_FLAG_LEX_BLOCK   (0x2U)  // a lexical block is pretty much a node in a control-flow graph
#define TYTHON_CONTEXT_FLAG_COMPLETE    (0x4U)  // a context is complete iff it is a lexical block and it is terminated
#define TYTHON_CONTEXT_FLAG_ASSIGN      (0x8U)  // an assignment context indicates that we are dealing in references instead of values

class Context {

friend class TythonBuilder;

private:
    std::map<std::string, llvm::Value*> variable_shadow_symbol_table;
    unsigned int flags;

public:
    Context* parent;
    llvm::BasicBlock* exit;

    explicit Context(Context* parent = nullptr, unsigned int flags = 0x0) :
        parent(parent),
        variable_shadow_symbol_table(),
        flags(flags),
        exit(nullptr) {};

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

    /**
     * Binds the specified value to the specified name.<br>
     * The name could only be registered in a parent context, in which case the binding will happen in the first parent with the registered name.
     * @param value The value to bind.
     * @param name The name of the symbol to bind to.
     * @return Returns a reference to the symbol.
     * @throws UnknownSymbolException Thrown when the specified name is not registered in this scope.
     */
    llvm::Value* bind(llvm::Value* value, const std::string& name);

    [[nodiscard]] unsigned int getFlags() const;

    [[nodiscard]] bool isGlobal() const;

    [[nodiscard]] bool isLoop() const;

    [[nodiscard]] bool isLexicalBlock() const;

    /**
     * Flags this context as completed (see TYTHON_CONTEXT_FLAG_COMPLETE).
     */
    void setComplete();

    [[nodiscard]] bool isComplete() const;

    [[nodiscard]] bool isAssign() const;

};


#endif //TYTHON_CONTEXT_H
