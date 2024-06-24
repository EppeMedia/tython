//
// Created by manzi on 21/02/24.
//

#ifndef TYTHON_API_H
#define TYTHON_API_H

#include "object.h"

#define SPEC_INT    0
#define SPEC_FLOAT  1
#define SPEC_OBJECT 2

typedef struct specialization {

    int32_t tag;

    union {
        long long integer;
        double floating_point;
        struct object_t* object;
    };

} specialization_t;

/************************
 * Hidden API functions *
 ************************/

void throw_type_error(specialization_t subject, int32_t expected_type);

specialization_t spec_pow(specialization_t base, specialization_t exponent);

/*************************
 * Visible API functions *
 *************************/

/**
 * Creates object wrappers for primitive types. Returns a specialization struct containing the object wrapper.<br>
 * If the specified specialization is already an object type, this is effectively a no-op.
 * @param spec The specialization to box.
 * @return Returns an specialization struct containing the object representation of the specified specialization.
 */
specialization_t box(specialization_t spec);

/**
 * Warning/Error OUT. Prints the specified value over stderr.
 * @param value The value identifying the cause of the warning or error.
 */
void ewout(specialization_t value);

/**
 * Prints the specified speialization value to standard out.
 * @param value The specialization value to print.
 */
void print(specialization_t value);

/**
 * Constructor for range object.
 * @param start The start index of the range object.
 * @param end The end index of the range object.
 * @param step The step size of the range iterator.
 * @return Returns an instance of a range object, wrapped in a specialization struct.
 */
specialization_t range(specialization_t start, specialization_t end, specialization_t step);

/**
 * Constructor for tuple objects.
 * @param count The number of elements the tuple contains.
 * @param ... The elements which make up the tuple. Elements must be of type specialization_t.
 * @return Returns an instance of a tuple object, wrapped in a specialization struct.
 */
specialization_t __tuple__(size_t count, ...);

/**
 * Constructor for list objects.
 * @param count The number of elements the list contains.
 * @param ... The elements which make up the list. Elements must be of type specialization_t.
 * @return Returns an instance of a list object, wrapped in a specialization struct.
 */
specialization_t __list__(size_t count, ...);

/**
 * Constructor for dict objects.
 * @param count The number of key-value pairs the dict contains.
 * @param ... The key-value pairs which make up the dict. Keys are followed by their corresponding value in an alternating fashion. All elements must be of type specialization_t.
 * @return Returns an instance of a dict object, wrapped in a specialization struct.
 */
specialization_t __dict__(size_t count, ...);

/**
 * Sets the specified value at the specified index on the speicified object.
 * @param object The object to set the specified value on.
 * @param key The index at which to set the specified value.
 * @param value The value to set.
 */
void __set__(specialization_t object, specialization_t key, specialization_t value);

/**
 * Determines the length of the specified object instance. Throws an assertion error if the object is not of a sequence or mapping type.
 * @param object The object instance to determine the length of.
 * @return Returns a new integer object instance which is the length of the specified object instance.
 */
specialization_t len(specialization_t object);

/**
 * Creates a new slice object with the specified properties.
 * @param start The start of the new slice.
 * @param end The end of the new slice.
 * @param step The step size of the new slice.
 * @return Returns a fresh instance of a slice with the specified properties.
 */
specialization_t slice(specialization_t start, specialization_t end, specialization_t step);

/**
 * Creates a new list with the ordered contents of the specified iterable object. Order is determined by the object's iterator.
 * @param obj The iterable object to create a list over.
 * @return Returns a new list containing the ordered elements of the iterable object. Order is determined by the object's iterator.
 */
specialization_t list(specialization_t obj);

/*
 * Creates a string representation of the specified specialization instance.
 * @return Returns a new string instance, representing the specified specialization instance.
 */
specialization_t str(specialization_t spec);

#endif //TYTHON_API_H
