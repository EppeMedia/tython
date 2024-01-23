
INCLUDE_DIRECTORIES(${tython_SOURCE_DIR}/lib/include)

ADD_LIBRARY(tython_lib STATIC class.c builtin/dictionary.c object.c type.c util.c)
