
INCLUDE_DIRECTORIES(${tython_SOURCE_DIR}/lib/include)

ADD_LIBRARY(tython_lib STATIC
        object.c
        type.c
        object/dictionaryobject.c
        object/integerobject.c
        object/floatobject.c
        object/stringobject.c
        object/basicland.c)
