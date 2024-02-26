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
antlr_target(TythonLexer src/grammar/TythonParser.g4 LEXER
        PACKAGE build)

# include generated files in project environment
include_directories(${ANTLR_TythonLexer_OUTPUT_DIR})

# end configure ANTLR

# runtime library
add_subdirectory(lib)
link_directories(${tython_lib_SOURCE_DIR}/include)

include_directories(include)
include_directories(${tython_lib_SOURCE_DIR}/include)

add_executable(tython src/main.cpp
        src/grammar/generated/TythonLexer.cpp
        src/grammar/generated/TythonParser.cpp
        src/lexer/TythonLexerBase.cpp
        src/ir/TythonModule.cpp
        src/utils/Utils.cpp
        src/ir/TythonBuilder.cpp
        src/visitor/SourceFileVisitor.cpp
        src/model/Context.cpp)

target_link_libraries(tython antlr4_shared ${llvm_libs} spdlog::spdlog tython_lib)
