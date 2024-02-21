//
// Created by manta on 11/10/22.
//

#ifndef TYTHON_BUILDER_H
#define TYTHON_BUILDER_H

#include <llvm/IR/IRBuilder.h>
#include "TythonModule.h"
#include "model/Namespace.h"
#include <string>

class TythonBuilder : public llvm::IRBuilder<> {

    friend class SourceFileVisitor;

private:

    llvm::StructType* object_type;
    llvm::StructType* typeobject_type;
    llvm::StructType* dict_entry_type;

    /*
     * Built-in type method structs
     */
    llvm::StructType* number_functions_type;
    llvm::StructType* mapping_functions_type;

    void init();
    void initFirstClassTypes();

    /**
     * Creates a new namespace as a child of the current namespace, and updates the current namespace pointer.
     * @return Returns the namespace pointer.
     */
    Namespace* nestNamespace();

    /**
     * Climbs the namespace tree by one level, and updates the current namespace pointer.
     * @return Returns the namespace pointer.
     */
    Namespace* popNamespace();

    TythonModule* module;
    Namespace* current_namespace;

public:
    TythonBuilder(TythonModule* module, llvm::BasicBlock* bb) : llvm::IRBuilder<>(bb),
                                                                module(module),
                                                                current_namespace(nullptr),
                                                                object_type(nullptr),
                                                                typeobject_type(nullptr),
                                                                number_functions_type(nullptr),
                                                                mapping_functions_type(nullptr) {
        init();
    };

    /**
     * Creates a variable in the current namespace.
     * @param name The name of the variable to create.
     * @return Returns the newly created variable.
     */
    llvm::Value* CreateVariable(const std::string& name);

    /**
     * Generates the instructions to obtain a reference to the typeobject instance of the specified object instance.
     * @param object_instance The object instance for which to get the typeobject reference.
     * @return Returns a reference to the specified object's typeobject
     */
    llvm::Value* CreateGetTypeObject(llvm::Value* object_instance);

    /**
     * Generates the instructions to obtain a reference to the specified typeobject's number_functions struct.
     * @param type_object The typeobject for which to get the number_functions struct reference.
     * @return Returns a reference to the specified typeobject's number_functions struct.
     */
    llvm::Value* CreateGetNumberFunctions(llvm::Value* type_object);

    /**
     * Generates the instructions to obtain a reference to the specified typeobject's mapping_functions struct.
     * @param type_object The typeobject for which to get the mapping_functions struct reference.
     * @return Returns a reference to the specified typeobject's mapping_functions struct.
     */
    llvm::Value* CreateGetMappingFunctions(llvm::Value* type_object);

    llvm::Value* CreateObjectIsTruthy(llvm::Value* object_instance);

    /**
     * Generates the instructions to numerically add two Tython objects.
     * @param lhs The lhs object of the sum.
     * @param rhs The rhs object of the sum.
     * @return Returns a reference to the result of the sum of the specified lhs and rhs.
     */
    llvm::Value* CreateTythonAdd(llvm::Value* lhs, llvm::Value* rhs);

    /**
     * Generates the instructions to perform a rich comparison between to the specified objects.
     * @param lhs The left-hand side of the comparison operation.
     * @param rhs The right-hand side of the comparison operation.
     * @param op The comparison operation to perform.
     * @return Returns an integer object with the result of the comparison.
     */
    llvm::Value* CreateRichCmp(llvm::Value *lhs, llvm::Value *rhs, int op);

    /**
     * Generates instructions to obtain the value associated with the specified key on the specified object.
     * @param object The object on which to find the value associated with the specified key.
     * @param key The key for which to find the associated value on the specified object.
     * @return Returns a reference to the value associated with the specified key on the specified object.
     */
    llvm::Value* CreateSubscript(llvm::Value* object, llvm::Value* key);

    /**
     * Generates the instructions to obtain a reference to a new iterator for the specified sequence object reference.
     * @param sequence The sequence to obtain a new iterator for.
     * @return Returns a reference to a new iterator of the specified sequence.
     */
    llvm::Value* CreateGetIterator(llvm::Value* sequence);

    /**
     * Generates the instructions to increment the specified iterator reference.
     * @param it The iterator to increment.
     * @return Returns the (stale) value of the iterator before the increment.
     */
    llvm::Value* CallIteratorNext(llvm::Value* it);

    /**
     * Generates the instructions to create a new integer object instance for the specified integer value.
     * @param content The integer value to create an integer object for.
     * @return Returns a reference to the new integer object.
     */
    llvm::Value* CreateIntObject(llvm::Value* content);

    /**
     * Generates the instructions to create a new float object instance for the specified floating-point value.
     * @param content The floating-point value to create a float object for.
     * @return Returns a reference to the new float object.
     */
    llvm::Value* CreateFloatObject(llvm::Value* content);

    /**
     * Generates the instructions to create a new string object for the specified c-style string reference.
     * @param cstr The c-style string reference to create a string object for.
     * @param length The lenght of the string object to create.
     * @return Returns a reference to the new string object.
     */
    llvm::Value* CreateStringObject(llvm::Value* cstr, llvm::Value* length);

    /**
     * Generates the instructions to create a dictionary object containing the {count} {entries}.
     * @param count The number of entries the new dictionary should contain.
     * @param entries The entries the dictionary should be initialized with.
     * @return Returns a reference to the newly created dictionary object.
     */
    llvm::Value* CreateDictLiteral(llvm::Value* count, std::vector<std::pair<llvm::Value*, llvm::Value*>>& entries);

    /**
     * Generates the instructions to create a list object containing the {count} {elements}.
     * @param count The number of elements the new list should contain.
     * @param elements The elements the list should be initialized with.
     * @return Returns a reference to the newly created list object.
     */
    llvm::Value* CreateListLiteral(llvm::Value* count, std::vector<llvm::Value*>& elements);

};

#endif // TYTHON_BUILDER_H
