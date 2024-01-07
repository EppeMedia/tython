CMAKE_MINIMUM_REQUIRED(VERSION 3.7 FATAL_ERROR)
project(tython)

set(CMAKE_CXX_STANDARD 17)
list(APPEND CMAKE_MODULE_PATH ${CMAKE_CURRENT_SOURCE_DIR}/cmake)

# find libraries
find_package(spdlog REQUIRED)
find_package(LLVM 15 REQUIRED CONFIG)

# configure LLVM

message(STATUS "Found LLVM ${LLVM_PACKAGE_VERSION}")
message(STATUS "Using LLVMConfig.cmake in: ${LLVM_DIR}")

include_directories(${LLVM_INCLUDE_DIRS})
separate_arguments(LLVM_DEFINITIONS_LIST NATIVE_COMMAND ${LLVM_DEFINITIONS})
add_definitions(${LLVM_DEFINITIONS_LIST})

llvm_map_components_to_libnames(llvm_libs ${LLVM_TARGETS_TO_BUILD} support core irreader codegen mc mcparser option)

# end configure llvm

# configure ANTLR

add_definitions(-DANTLR4CPP_SHARED)

# add external build for antlrcpp
include(ExternalAntlr4Cpp)
# add antrl4cpp artifacts to project environment
include_directories(${ANTLR4_INCLUDE_DIRS})

# set variable pointing to the antlr tool that supports C++
# this is not required if the jar file can be found under PATH environment
set(ANTLR_EXECUTABLE ${CMAKE_CURRENT_SOURCE_DIR}/thirdparty/antlr/antlr-4.11.1-complete.jar)
# add macros to generate ANTLR Cpp code from grammar
find_package(ANTLR REQUIRED)

# Call macro to add lexer and grammar to your build dependencies.
antlr_target(TythonLexer ${CMAKE_CURRENT_SOURCE_DIR}/grammar/Tython.g4 LEXER
        PACKAGE build)

# include generated files in project environment
include_directories(${ANTLR_TythonLexer_OUTPUT_DIR})

# end configure ANTLR

add_executable(tython main.cpp
        include/parser/TythonLexer.h
        include/parser/TythonLexer.cpp
        include/parser/TythonParser.h
        include/parser/TythonParser.cpp
        include/visitor/SourceFileVisitor.h
        src/ir/TythonModule.cpp
        include/exception/NotImplemented.h
        include/exception/CompileException.h
        src/model/Variable.cpp
        include/model/Variable.h
        include/ir/TythonModule.h
        include/exception/CompileException.h
        include/utils/Utils.h
        src/utils/Utils.cpp
        include/exception/CompileException.h
        include/ir/TythonBuilder.h
        src/ir/TythonBuilder.cpp
        src/visitor/SourceFileVisitor.cpp
        src/model/Value.cpp
        include/model/Scope.h
        src/model/Scope.cpp)

target_link_libraries(tython antlr4_shared ${llvm_libs} spdlog::spdlog)
