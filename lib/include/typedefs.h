//
// Created by manzi on 20/01/24.
//

#ifndef TYTHON_TYPEDEFS_H
#define TYTHON_TYPEDEFS_H

#include <inttypes.h>

typedef struct object_t object;
typedef struct type_t type;

#define ObjectHead object obj_base;
#define CollectionObjectHead collection_object collection_obj_base;

#define AS_OBJECT(instance) ((object*)instance)

typedef uint64_t size_t;

#endif //TYTHON_TYPEDEFS_H
