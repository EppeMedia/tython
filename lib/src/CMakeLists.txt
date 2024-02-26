
INCLUDE_DIRECTORIES(${tython_SOURCE_DIR}/lib/include)

ADD_LIBRARY(tython_lib STATIC
        object.c
        type.c
        object/noneobject.c
        object/boolobject.c
        object/integerobject.c
        object/floatobject.c
        object/stringobject.c
        object/tupleobject.c
        object/listobject.c
        object/rangeobject.c
        object/sliceobject.c
        object/dictobject.c
        api/api.c
        bridge/basicland.c)
