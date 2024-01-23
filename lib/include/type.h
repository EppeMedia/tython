//
// Created by manzi on 20/01/24.
//

#ifndef TYTHON_TYPE_H
#define TYTHON_TYPE_H

#include "typedefs.h"
#include "object.h"

/*
 * The following OP codes are for rich comparisons between objects. This corresponds to infix boolean comparisons like '==', '!=', '>=', etc.<br>
 * <i><b>Note</b>: reminder that rich comparisons check value, <b>not identity</b>.</i><br>
 * <br>
 * The OP codes are identical to those of the CPython reference implementation.
 */
#define tython_lt 0
#define tython_lte 1
#define tython_eq 2
#define tython_neq 3
#define tython_gt 4
#define tython_gte 5


/*
 * Function type defs
 */

/**
 * Interface for rich comparison between objects (i.e. EQ, NEQ, LT, GTE).
 * Definitions of OP codes are in type.h
 */
typedef object* (*rich_compare)(object*, object*, int op);

typedef object* (*unary_f)(object*);
typedef object* (*binary_f)(object*, object*);
typedef int (*evaluate)(object*);

/*
 * Built-in data structures and their operations.
 */

/**
 * This struct describes the set of all possible operations on number-like types.
 */
typedef struct number_functions_t {
    evaluate to_bool;
} number_functions;

/**
 * This is the set of all possible operations operations on mapping data structures.
 */
typedef struct mapping_functions_t {
    unary_f length;    // length of the map
    binary_f subscript; // access by key
} mapping_functions;

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

    /*
     * Built-in functions (ungrouped). These should be set for all types.
     */
    rich_compare rich_compare;

    /*
     *  Built-in data operations. If not set, this type does not support that class of operations.
     */
    number_functions* number_functions;
    mapping_functions* mapping_functions;

} type;

/*
 * This is the globally unique "type of types".
 */
type type_type;

/**
 * Allocates memory for an object instance of type {typeobj} and initialises its core properties (see ObjectHead).
 * @param typeobj The type of of the object instance to allocate memory for.
 * @return Returns a pointer to freshly a allocated object with its core properties initialised.
 */
object* alloc(type* typeobj);

/**
 * Allocates memory for a collection of type typeobj, allowing for {number} elements.
 * The collection's core properties (see ObjectHead) are initialised, the rest of the fields are not.
 * Note that nothing will be inserted into the list, and the collection's items are thus undefined.
 * @param typeobj The type of the collection for which to allocate memory.
 * @param number The number of elements to provision for.
 * @return Returns a fresh collection instance pointer with its core properties initialised and space for {number} elements.
 */
collection_object* alloc_collection(type* typeobj, size_t number);

#endif //TYTHON_TYPE_H
