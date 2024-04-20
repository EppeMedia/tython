//
// Created by manzi on 20/01/24.
//

#include "../include/type.h"
#include <stdlib.h>
#include <assert.h>
#include <stdio.h>
#include <gc.h>

//#define malloc(n) GC_malloc(n)
//#define calloc(n, m) GC_malloc((n)*(m))
//#define realloc(n, m) GC_realloc(n, m)

/**
 * The type "type" cannot be instantiated, hence all its instance details are unimportant (set to null).
 */
type_object type_type = {
        .obj_base           = {
            .identity       = &type_type.obj_base,
            .type           = &type_type,
            .refs           = 0
        },

        .alloc              = NULL,
        .seqalloc           = NULL,

        .base               = NULL,
        .instance_size      = 0,
        .item_size          = 0,

        .rich_compare       = NULL,

        .number_functions   = NULL,
        .mapping_functions  = NULL,
        .sequence_functions = NULL,
};

struct memory_pool_t {
    void* pool;
    void* head;
    size_t size; // in bytes
}* memory_pools;
size_t pool_count = 0;
size_t object_count = 0;
//= {
//        .pool = NULL,
//        .head = NULL,
//        .size = 0
//};

static void init_memory_pool(void) {

    const size_t size = 128 * sizeof(object); // todo: find a good heuristic for a starting size

    pool_count = 1;
    struct memory_pool_t* new_pool = malloc(sizeof(struct memory_pool_t));

    new_pool->pool = malloc(size);
    new_pool->head = new_pool->pool;
    new_pool->size = size;

    memory_pools = malloc(sizeof(struct memory_pool_t));
    memory_pools[0] = *new_pool;
    printf("Malloced %lu bytes\r\n", size);
}

/**
 * "Allocates" float objects from a memory pool. This is currently quite contrived
 * -- if it performs well, this should be standardized in the type.c#default_alloc function.
 * @param typeobj The type of the object to allocate (we expect only floats here).
 * @return Returns a newly "allocated" float object.
 */
object* pool_alloc(type_object* typeobj) {

    return default_alloc(typeobj);

    if (pool_count == 0) {
        init_memory_pool();
    }

    struct memory_pool_t memory_pool = memory_pools[pool_count - 1];

    const size_t object_size = typeobj->instance_size;

    // check if we have enough space in our pool to fit another object
    if (((char*)memory_pool.head) + object_size > ((char*)memory_pool.pool) + memory_pool.size) {
        // we cannot fit it; create another pool with double the space

        ++pool_count;

//        printf("Creating new memory pool (%lu)...\r\n", pool_count);

//        printf("Object size: %lu\r\nPool: %p\r\nHead: %p\r\nEnd: %p\r\n",
//               object_size,
//               memory_pool.pool,
//               memory_pool.head,
//               ((char*)memory_pool.pool) + memory_pool.size);

        struct memory_pool_t* new_pool = malloc(sizeof(struct memory_pool_t));

        assert(new_pool != NULL);

        const size_t new_size = memory_pool.size * 2;

        new_pool->pool = malloc(new_size);
        new_pool->head = new_pool->pool;
        new_pool->size = new_size;
//        printf("Created new pool (%lu) with %lu bytes\r\n", pool_count, new_size);

        memory_pool = *new_pool;

        // track pool
        memory_pools = realloc(memory_pools, pool_count * sizeof(struct memory_pool_t));
    }

    // obtain a pointer to the memory region
    const void* object_ptr = memory_pool.head;
    // advance head
    memory_pool.head = (void*)(((char*)memory_pool.head) + object_size);

    memory_pools[pool_count - 1] = memory_pool;

//    ++object_count;
//    if (object_count % 1000000 == 0) {
//        printf("obj #%lu\r\n", object_count);
//    }

    object* obj = AS_OBJECT(object_ptr);

    obj->identity = obj;
    obj->type = typeobj;

    return obj;
}

object* default_alloc(type_object* typeobj) {
    return (object*) default_seqalloc(typeobj, 0);
}

object* default_seqalloc(type_object* typeobj, size_t n) {

    const size_t size = typeobj->instance_size + (n * typeobj->item_size);

    object* obj = malloc(size);

    obj->identity = obj;
    obj->type = typeobj;
    obj->refs = 0;

    return obj;
}

void default_grab(object* instance) {

    GRAB_OBJECT(instance);
}

void default_release(object* instance) {

    assert(instance->refs > 0);

    instance->refs--;

    if (instance->refs == 0) {
        // release this object
//        printf("Releasing object %p...\r\n", instance);
        free(instance);
    }
}
