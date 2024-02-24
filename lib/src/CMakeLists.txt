
INCLUDE_DIRECTORIES(${tython_SOURCE_DIR}/lib/include)

ADD_LIBRARY(tython_lib STATIC
        object.c
        type.c
        object/noneobject.c
        object/integerobject.c
        object/rangeobject.c
        object/floatobject.c
        object/stringobject.c
        object/boolobject.c
        object/dictobject.c
        object/listobject.c
        object/tupleobject.c
        function/userfunctions.c
        bridge/basicland.c)
