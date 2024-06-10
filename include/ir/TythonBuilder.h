//
// Created by manta on 11/10/22.
//

#ifndef TYTHON_BUILDER_H
#define TYTHON_BUILDER_H

#include <llvm/IR/IRBuilder.h>
#include "TythonModule.h"
#include "model/Context.h"
#include "utils/Utils.h"
#include <string>

class TythonBuilder : public llvm::IRBuilder<> {

    friend class SourceFileVisitor;

private:

    const configuration_t* config;

    llvm::StructType* object_type;
    llvm::StructType* typeobject_type;

    /*
     * Built-in type method structs
     */
    llvm::StructType* number_functions_type;
    llvm::StructType* mapping_functions_type;

    llvm::Value* none_object_instance;

    void init();
    void initFirstClassTypes();

    /**
     * Creates a new context as a child of the current context, and updates the current context pointer.
     * @return Returns the context pointer.
     */
    class Context* nestContext(unsigned int flags = 0x0);

    /**
     * Climbs the context tree by one level, and updates the current context pointer.
     * @param free Controls whether or not variables declared in the current context should be freed.
     * @return Returns the context pointer.
     */
    class Context* popContext(bool free = true);

    TythonModule* module;
    class Context* current_context;

    /**
     * Creates a call to the specified binary number function using the specified operands.
     * @param number_function_slot The slot from which to load the number function.
     * @param lhs The left-hand side of the binary operation (this must be an object pointer).
     * @param rhs The right-hand side of the binary operation (this must be an object pointer).
     * @return Returns the result of the number function call.
     */
    llvm::Value* CreateBinaryNumberFunctionCall(size_t number_function_slot, llvm::Value* lhs, llvm::Value* rhs);

public:
    TythonBuilder(TythonModule* module, llvm::BasicBlock* bb, const configuration_t* config) : llvm::IRBuilder<>(bb),
                                                                module(module),
                                                                config(config),
                                                                current_context(nullptr),
                                                                object_type(nullptr),
                                                                typeobject_type(nullptr),
                                                                number_functions_type(nullptr),
                                                                mapping_functions_type(nullptr),
                                                                none_object_instance(nullptr) {
        init();
    };

    /**
     * Creates a variable in the current context.
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

    /**
     * Generates the instructions for assigning one specialization union to another.
     * @param assignee The specialization union to assign to.
     * @param value The specialization union to assign.
     * @return Returns a reference to the assignee.
     */
    llvm::Value* CreateAssign(llvm::Value* assignee, llvm::Value* value);

    /**
     * Generates instructions top test the specified subject for truthiness.
     * @param subject The subject to test for truthiness. Must be a specialization type.
     * @return Returns an integer primitive greater than zero iff the subject is truthy.
     */
    llvm::Value* CreateObjectIsTruthy(llvm::Value* subject);

    llvm::Value* CreateResolveBuiltinMethod(llvm::Value* object, llvm::Value* name);

    /**
     * Wraps binary operations in a dynamic type guard.
     * @param lhs The left-hand side of the binary operation.
     * @param rhs The right-hand side of the binary operation.
     * @param specialized_case_handler This receives two primitive values, perform a binop instruction and return the result of that operation.
     * @param dynamic_runtime_handler This receives two OBJECT pointers, and should delegate control to the right runtime calls.
     */
    llvm::Value* CreateBinop(llvm::Value* lhs, llvm::Value* rhs,
                             const std::function<llvm::Value* (llvm::Value*, llvm::Value*)>& specialized_int_case_handler,
                             const std::function<llvm::Value* (llvm::Value*, llvm::Value*)>& specialized_float_case_handler,
                             const std::function<llvm::Value* (llvm::Value*, llvm::Value*)>& dynamic_runtime_handler);

    /**
     * Generates the instructions to numerically add two Tython objects.
     * @param lhs The lhs object of the sum.
     * @param rhs The rhs object of the sum.
     * @return Returns a reference to the result of the sum of the specified lhs and rhs.
     */
    llvm::Value* CreateTythonAdd(llvm::Value* lhs, llvm::Value* rhs);

    /**
 * Generates the instructions to numerically subtract two Tython objects.
 * @param lhs The lhs object of the subtraction.
 * @param rhs The rhs object of the subtraction.
 * @return Returns a reference to the result of the subtraction of the specified lhs and rhs.
 */
    llvm::Value* CreateTythonSub(llvm::Value* lhs, llvm::Value* rhs);

    /**
 * Generates the instructions to numerically multiply two Tython objects.
 * @param lhs The lhs object of the multiplication.
 * @param rhs The rhs object of the multiplication.
 * @return Returns a reference to the result of the multiplication of the specified lhs and rhs.
 */
    llvm::Value* CreateTythonMult(llvm::Value* lhs, llvm::Value* rhs);

    /**
 * Generates the instructions to numerically divide two Tython objects.
 * @param lhs The lhs object of the division.
 * @param rhs The rhs object of the division.
 * @return Returns a reference to the result of the division of the specified lhs and rhs.
 */
    llvm::Value* CreateTythonDiv(llvm::Value* lhs, llvm::Value* rhs);

    /**
 * Generates the instructions to numerically exponentiate the lhs (base) object by the rhs (exponent) object.
 * @param lhs The lhs object (base) of the exponentiation.
 * @param rhs The rhs object of the exponent.
 * @return Returns a reference to the result of the exponentiation of the specified lhs (base) and rhs (exponent).
 */
    llvm::Value* CreateTythonExp(llvm::Value* lhs, llvm::Value* rhs);

    /**
     * Generates the instructions to perform a rich comparison between to the specified objects.
     * @param lhs The left-hand side of the comparison operation.
     * @param rhs The right-hand side of the comparison operation.
     * @param op The comparison operation to perform.
     * @return Returns an integer object with the result of the comparison.
     */
    llvm::Value* CreateRichCmp(llvm::Value *lhs, llvm::Value *rhs, int op);

    /**
     * Generates instructions to obtain a reference to the value associated with the specified key on the specified object.
     * @param object The object on which to find a reference to the value associated with the specified key.
     * @param key The key for which to find the associated value on the specified object.
     * @return Returns a reference to the value associated with the specified key on the specified object.
     */
    llvm::Value* CreateSubscript(llvm::Value* object, llvm::Value* key);

    /**
     * Generates instructions to obtain a slice of the specified sequence object.
     * @param object The sequence object from which to take a slice.
     * @param slice The slice indices to take from the specified object.
     * @return Returns a slice of the specified sequence object.
     */
    llvm::Value* CreateTakeSlice(llvm::Value* object, llvm::Value* slice);

    /**
     * Generates the instructions to obtain a reference to a new iterator for the specified sequence object reference.
     * @param sequence The sequence to obtain a new iterator for.
     * @return Returns a reference to a new iterator of the specified sequence.
     */
    llvm::Value* CreateGetIterator(llvm::Value* sequence);

    /**
     * Generates the instructions to increment the specified iterator reference.
     * @param it_primitive The iterator to increment.
     * @return Returns the (stale) value of the iterator before the increment.
     */
    llvm::Value* CallIteratorNext(llvm::Value* it_primitive);

    /**
     * Creates a specialization struct around the global none instance.
     */
    llvm::Value* CreateNoneSpec();

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

    /**
     * Generates the instructions to create a __tuple__ object containing the {count} {elements}.
     * @param count The number of elements the new __tuple__ should contain.
     * @param elements The elements the __tuple__ should be initialized with.
     * @return Returns a reference to the newly created __tuple__ object.
     */
    llvm::Value* CreateTupleLiteral(llvm::Value* count, std::vector<llvm::Value*>& elements);

    /**
     * Generates the instructions to grab a reference to the specified object.
     * @param object The object to grab a reference to.
     */
    void CreateGrabObject(llvm::Value* object);

    /**
     * Generates the instructions to release a reference to the specified object.
     * @param object The object to be released.
     */
    void CreateReleaseObject(llvm::Value* object);

    /**
     * Creates a zero-initialized instance of a specialization union.
     * @return Returns a zero-initialized instance of a specialization struct.
     */
    llvm::Value* CreateSpecInstance();

    /**
     * Creates a specialized type/value struct.
     * @param type_enum The type of the specialization.
     * @param value The value which is of type {type_enum}.
     * @param name The name of the instance (only used if the instance is non-local).
     * @param forceGlobal Indicates whether the instance should be global generated as a global (regardless of context).
     */
    llvm::Value* CreateSpecInstance(int32_t type_enum, llvm::Value* value, std::string name = "", bool forceGlobal = false);

    /**
     * Generates the instructions to copy the specified specialization instance to the specified target.
     * Note that the target should have at least sizeof(specialization_type) bytes of writable memory.
     * @param spec_instance The specialization instance to copy.
     * @param target The target to copy into.
     * @return Returns a reference to the target.
     */
    llvm::Value* CreateCopySpec(llvm::Value* spec_instance, llvm::Value* target);

    /**
     * Creates a type guard for the specified guardee value, invoking the code generated by the specified handler at runtime, depending on the type tag of the guardee.
     * If the runtime type tag is not INT, FLOAT, or OBJECT, or if the handler is a nullpointer, this throws a type error (the code generated by the object handler is not called).
     *
     * @param guardee The specialization object to be guarded.
     * @param int_handler The integer handler. Receives a primitive i64 value. Must return a specialization struct.
     * @param float_handler The float handler. Receives a primitive f64 value. Must return a specialization struct.
     * @param object_handler The object handler. Receives a primitive object reference (ptr). Must return a specialization struct.
     * @return Returns a reference to the result of the invoked handler at runtime. This is a specialization struct.
     */
    llvm::Value* CreateTypeGuard(llvm::Value *guardee,
                                 const std::function<llvm::Value* (llvm::Value*)> &int_handler,
                                 const std::function<llvm::Value* (llvm::Value*)> &float_handler,
                                 const std::function<llvm::Value* (llvm::Value*)> &object_handler);

    /**
     * Creates a type guard for the specified guardee value, invoking the code generated by the specified object_handler handler if the runtime type tag of the guardee is SPEC_OBJECT.
     * Otherwise, throws a type error (the code generated by the object handler is not called).
     * <br>
     * The specified object handler receives an object pointer, <b>not</b> a specialization struct.
     * @param guardee The value to guard at runtime.
     * @param object_handler The handler which generates the object handler code. Receives a primitive object reference (ptr). Must return a specialization struct.
     * @return Returns the result of the object handler.
     */
    llvm::Value* CreateObjectTypeGuard(llvm::Value* guardee, const std::function<llvm::Value* (llvm::Value*)>& object_handler);

    /**
     * Generates the instructions to box the specified specialization value:<br>
     * box({ INT, i }) -> { OBJ, integer_object(i) }<br>
     * box({ FLOAT, f }) -> { OBJ, float_object(f) }<br>
     * box({ OBJ, o }) -> { OBJ, o }<br>
     *
     * @param value The specialization value to box.
     * @return Returns a boxed representation of the specified specialization value.
     */
    llvm::Value* CreateBox(llvm::Value* value);

    /**
     * Generates the instructions to take to primitive object pointer out of the specified specialization value.
     * @param value The specialization value to take the primitive object pointer out of.
     * @return Returns the primitive object pointer contained inside the specified specialization value.
     */
    llvm::Value* CreateGetObjectPrimitive(llvm::Value* value);

    /**
     * Gets the type tag of the specified specialization union.
     * @param spec The specialization union to get the type tag of.
     * @return Returns the type tag related to the specified specialization union.
     */
    llvm::Value* getTag(llvm::Value* spec);

    /**
     * Sets the type tag of the specified specialization union to the specified value.
     * @param spec The specialization union to set the type tag of.
     * @param value The value to set the tag to.
     * @return Returns the specialization union with the tag set.
     */
    llvm::Value* setTag(llvm::Value* spec, llvm::Value* value);

    /**
     * Gets the content of the specified specialization union.
     * @param spec The specialization union to get the content of.
     * @return Returns the content related to the specified specialization union.
     */
    llvm::Value* getContent(llvm::Value* spec);

    /**
     * Sets the content of the specified specialization union to the specified value.
     * @param spec The specialization union to set the content of.
     * @param value The value to set the content to.
     * @return Returns the specialization union with the content set.
     */
    llvm::Value* setContent(llvm::Value* spec, llvm::Value* value);

};

#endif // TYTHON_BUILDER_H
