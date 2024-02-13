
INCLUDE_DIRECTORIES(${tython_SOURCE_DIR}/lib/include)

ADD_LIBRARY(tython_lib STATIC
        object.c
        type.c
        object/integerobject.c
        object/floatobject.c
        object/stringobject.c
        object/boolobject.c
        object/dictobject.c
        bridge/basicland.c)
