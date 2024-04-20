//
// Created by manzi on 20/01/24.
//

#ifndef TYTHON_TYPE_H
#define TYTHON_TYPE_H

#include "typedefs.h"
#include "object.h"

/**
 * Type slots describe the field offset in the type struct.
 * This is included in this header so that users of the library can used named offsets instead of magic numbers.
 */
#define TYTHON_TYPE_SLOT_RICH_COMPARE       8
#define TYTHON_TYPE_SLOT_NUMBER_FUNCTIONS   11
#define TYTHON_TYPE_SLOT_MAPPING_FUNCTIONS  12
#define TYTHON_TYPE_SLOT_SEQUENCE_FUNCTIONS 13
#define TYTHON_TYPE_SLOT_ITERATOR_CREATE    14
#define TYTHON_TYPE_SLOT_ITERATOR_NEXT      15
#define TYTHON_TYPE_SLOT_GRAB               17
#define TYTHON_TYPE_SLOT_RELEASE            18

/*
 * The following OP codes are for rich comparisons between objects. This corresponds to infix boolean comparisons like '==', '!=', '>=', etc.<br>
 * <i><b>Note</b>: reminder that rich comparisons check value, <b>not identity</b>.</i><br>
 * <br>
 * The OP codes are identical to those of the CPython reference implementation.
 */
#define TYTHON_CMP_OP_LT        0
#define TYTHON_CMP_OP_LTE       1
#define TYTHON_CMP_OP_EQ        2
#define TYTHON_CMP_OP_NEQ       3
#define TYTHON_CMP_OP_GT        4
#define TYTHON_CMP_OP_GTE       5

#define TYTHON_CMP_RES_ERR      (-1)

#define NUMBER_RICH_COMPARE(lhs, rhs, op)                           \
    switch (op) {                                                   \
        case TYTHON_CMP_OP_LT:                                      \
            return TO_INT(lhs < rhs);                               \
        case TYTHON_CMP_OP_LTE:                                     \
            return TO_INT(lhs <= rhs);                              \
        case TYTHON_CMP_OP_EQ:                                      \
            return TO_INT(lhs == rhs);                              \
        case TYTHON_CMP_OP_NEQ:                                     \
            return TO_INT(lhs != rhs);                              \
        case TYTHON_CMP_OP_GTE:                                     \
            return TO_INT(lhs >= rhs);                              \
        case TYTHON_CMP_OP_GT:                                      \
            return TO_INT(lhs > rhs);                               \
        default:                                                    \
            return TO_INT(TYTHON_CMP_RES_ERR);                      \
    }

#define GRAB_OBJECT(instance) (++instance->refs)

/*
 * Function type defs
 */

/**
 * Allocation functions are responsible for allocating memory for object instances of their type.
 */
typedef object* (*alloc_f)(type_object*);

/**
 * Sequence allocation functions are responsible for allocating memory for object instances of their type, provisioning space for {n} elements.
 */
typedef object* (*seqalloc_f)(type_object*, size_t);

/**
 * Grab functions are responsible for incrementing the reference counter of object instances.
 */
typedef void (*grab_f)(object*);

/**
 * Release functions are responsible for decrementing the reference counter of object instances.
 */
typedef void (*release_f)(object*);

/**
 * Interface for rich comparison between objects (i.e. EQ, NEQ, LT, GTE).<br>
 * Definitions of OP codes are in type.h
 *
 * @param lhs The left-hand side of the comparison operation.
 * @param rhs The right-hand side of the comparison operation.
 * @param op The OP code of the operation.
 */
typedef object* (*rich_compare_f)(object* lhs, object* rhs, int op);

/**
 * Representation functions convert the object into another object for presentation. An example is the str function which creates a string representing the object instance.
 */
typedef object* (*repr_f)(object*);

/**
 * Subscript functions return a reference to a value indexed by a key.
 *
 * @param mapping_obj The container object to obtain the indexed key from.
 * @param key The key by which to find the indexed value reference.
 */
typedef object** (*subscript_f)(object* mapping_obj, object* key);

typedef object* (*unary_f)(object*);
typedef object* (*binary_f)(object*, object*);

/**
 * All functions are expected to return an object since there is no void type.
 * Functions that do not return any value will invariably return the None object instance.
 */
typedef object* (function_object_function)();

/**
 * Builtin methods do not contain function object, and do not record the number of arguments a function takes.
 */
typedef struct builtin_method_t {

    const char* name;
    function_object_function* f;

} builtin_method;

/*
 * Built-in data structures and their operations.
 */

/**
 * This struct describes the set of all possible operations on number-like types.
 */
typedef struct number_functions_t {

    unary_f to_bool;
    unary_f to_int;
    unary_f to_float;

    binary_f add;   // adds one number to another
    binary_f sub;   // subtracts the right-hand argument from the first-hand argument
    binary_f mult;  // multiplies lhs with rhs
    binary_f div;   // divides lhs by rhs
    binary_f exp;   // exponentiates lhs by rhs

} number_functions;

/**
 * This is the set of all possible operations operations on mapping data structures.
 */
typedef struct mapping_functions_t {

    unary_f length;         // length of the map
    subscript_f subscript;  // (object* mapping_obj, object* key), obtain value reference by key

} mapping_functions;

/**
 * This is the set of all possible operations on sequence objects.
 */
typedef struct sequence_functions_t {

    unary_f length;         // length of the sequence
    binary_f take_slice;    // take a slice of this sequence

} sequence_functions;

/**
 * Types are objects. They are reference by other objects to provide runtime information about the properties of an object, and the operations it supports.<br>
 * The properties of this type struct are exhaustive (instances to do not extend it like other objects do). This means that not all fields will be set for all types.<br>
 * Unsupported operations have function pointers set to NULL.
 * <br>
 * Certain operations are grouped in a struct containing function pointers. If that struct is not set on a type, it does not support any of the functions in that group. Each operation in a grouping can also be individually supported or not: unsupported operations have function pointers set to NULL.<br>
 * For example, the struct mapping_functions contains the "length" operation. For a list, this returns the number of elements in that list. For a number (i.e. the literal 7) this operation is not supported (there are no semantics defined for what the length of a number is). Therefore the "length" function pointer on number_type is set to NULL.<br>
 * <br>
 * There is a globally unique type which is the "type" type. It ends the pointer graph traversal when resolving types by having a self-cycle.
 */
typedef struct type_t {
    ObjectHead

    struct type_t* base;            // parent type
    size_t instance_size;           // size of an instance of this type in bytes
    size_t item_size;               // if this type is a sequence type, this is the size of each of its elements in bytes

    alloc_f alloc;                  // the function allocating memory for object instances of this type
    seqalloc_f seqalloc;            // the function allocating memory for sequence object instances of this type (must be set if the type is a sequence type)

    /*
     * Built-in functions (ungrouped). These should be set for all types.
     */
    rich_compare_f rich_compare;    // the rich comparison function, which may allow for (in)equality checks and relative ordinance.
    repr_f str;                     // the function that creates a string representation for an object instance.
    unary_f hash;                   // takes an object instance of this type and returns a hash for it of type int_object

    /*
     *  Built-in data operations. If not set, this type does not support that class of operations.
     */
    struct number_functions_t* number_functions;
    struct mapping_functions_t* mapping_functions;
    struct sequence_functions_t* sequence_functions;

    /**
     * Iterator functions.
     */
    unary_f create_iterator;        // creates an iterator for this type
    unary_f iterator_next;          // the iterator increment function, if this type is an iterator

    builtin_method* methods;        // the built-in methods on instances of this type. Must end with sentinel a tuple of NULLs. Does not contain user-defined methods.

    grab_f grab;                    // obtains a reference to an instances of this type.
    release_f release;              // releases a reference to an instances of this type.

} type_object;

/*
 * This is the globally unique "type of types".
 */
extern type_object type_type;

/**
 * Allocates memory for an object instance of type {typeobj} and initialises its core properties (see ObjectHead).
 * @param typeobj The type of the object instance to allocate memory for.
 * @return Returns a pointer to a freshly allocated object with its core properties initialised.
 */
object* default_alloc(type_object* typeobj);

/**
 * Allocates pooled memory for an object instance of type {typeobj} and initialises its core properties (see ObjectHead).
 * @param typeobj The type of of the object instance to allocate pooled memory for.
 * @return Returns a pointer to a freshly pool-allocated object with its core properties initialised.
 */
object* pool_alloc(type_object* typeobj);

/**
 * Allocates memory for an sequence object instance of type {typeobj} and initialises its core properties (see ObjectHead).<br>
 * The memory region is large enough for {n} elements, none of which are initialized.
 * @param typeobj The type of of the object instance to allocate memory for.
 * @param n The number of elements the memory space should provision for.
 * @return Returns a pointer to freshly a allocated object with its core properties initialised.
 */
object* default_seqalloc(type_object* typeobj, size_t n);

/**
 * Increments the reference counter of the specified object instance.
 * @param instance The object instance to increment the reference counter of.
 */
void default_grab(object* instance);

/**
 * Decrements the reference counter of the specified object instance.
 * @param instance The object instance to decrement the reference counter of.
 */
void default_release(object* instance);

#endif //TYTHON_TYPE_H
