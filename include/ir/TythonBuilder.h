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

    /*
     * Built-in type method structs
     */
    llvm::StructType* number_functions_type;

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
                                                                number_functions_type(nullptr) {
        init();
    };

    /**
     * Creates a variable in the current namespace.
     * @param name The name of the variable to create.
     * @return Returns the newly created variable.
     */
    llvm::Value* CreateVariable(std::string& name);

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

    llvm::Value* CreateObjectIsTruthy(llvm::Value* object_instance);

    /**
     * Generates the instructions to obtain a reference to the specified number_functions struct's to_bool function.
     * @param number_functions_struct The number_functions struct for which to obtain the to_bool function pointer.
     * @return Returns a reference to the to_bool function pointer of the specified number_functions struct
     */
    llvm::Value* CreateGetNumberToBool(llvm::Value* number_functions_struct);

    /**
     * Generates the instructions to obtain a reference to the specified number_functions struct's to_int function.
     * @param number_functions_struct The number_functions struct for which to obtain the to_int function pointer.
     * @return Returns a reference to the to_int function pointer of the specified number_functions struct
     */
    llvm::Value* CreateGetNumberToInt(llvm::Value* number_functions_struct);

    /**
     * Generates the instructions to obtain a reference to the specified number_functions struct's to_float function.
     * @param number_functions_struct The number_functions struct for which to obtain the to_float function pointer.
     * @return Returns a reference to the to_float function pointer of the specified number_functions struct
     */
    llvm::Value* CreateGetNumberToFloat(llvm::Value* number_functions_struct);

    /**
     * Generates the instructions to perform a rich comparison between to the specified objects.
     * @param lhs The left-hand side of the comparison operation.
     * @param rhs The right-hand side of the comparison operation.
     * @param op The comparison operation to perform.
     * @return Returns an integer object with the result of the comparison.
     */
    llvm::Value* CreateRichCmp(llvm::Value *lhs, llvm::Value *rhs, int op);

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
     * Generates the instructions to create a string object representation for the specified object instance.
     * @param object The object instance for which to create a string representation.
     * @return Returns a string object representation for the specified object instance.
     */
    llvm::Value* CreateObjectToString(llvm::Value* object);

};

#endif // TYTHON_BUILDER_H
