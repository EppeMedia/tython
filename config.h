//
// Created by manzi on 6/20/23.
//
#ifndef TYTHON_CONFIG_H
#define TYTHON_CONFIG_H

#include <optional>

#define TYTHON_VERSION              "v0.1"

#define GC_ENABLED                  false

// program arguments
#define FLAG_HELP                   "--help"            // prints a help message and exits
#define FLAG_HELP_SHORT             "-?"
#define FLAG_HELP_UNHELPFUL         "-🤔"
#define FLAG_VERBOSE                "--verbose"         // print more messages to STD out
#define FLAG_VERBOSE_SHORT          "-v"
#define FLAG_MAIN                   "--main"
#define FLAG_MAIN_SHORT             "-m"
#define FLAG_LINK_OBJECTS           "--link"            // the object files we want to include when linking
#define FLAG_LINK_OBJECTS_SHORT     "-l"
#define FLAG_EMIT_LLVM              "-emit-llvm"        // Clang-like argument to emit llvm IR to the specified directory
#define FLAG_EMIT_DEBUG             "--debug"           // Enable debug symbols in the artefact, disable optimizations
#define FLAG_EMIT_DEBUG_SHORT       "-d"
#define FLAG_BUILD_DIR              "--build-dir"       // specify a directory for build artefacts
#define FLAG_BUILD_DIR_SHORT        "-b"
#define FLAG_OUTPUT                 "--out"             // specifies the executable artefact's filename
#define FLAG_OUTPUT_SHORT           "-o"
#define FLAG_NO_SPECIALIZE          "--no-specialize"   // determines whether or not to apply the specialization on literals
#define FLAG_NO_SPECIALIZE_SHORT    "-n"

#define MSG_HELP                    "USAGE: tython <src...> <options>\n\nWhere <src...> are the space-separated (relative) paths to the tython source files. Does not support directories.\n\nOPTIONS:\n\n--help, -?, -🤔: Display this help message and exit.\n\n--verbose, -v: Print more messages to STD out.\n\n--main, -m <src>: Specifies the artefact entry point. If the target artefact is an executable, exactly one source file must be specified as the entry point. Note: if the specified source file is also included in the list of sources (the first compiler argument <src...>), it is not compiled twice, and its order or inclusion is still the order of inclusion as specified in the first argument.\n\n--build-dir, -b <directory>: Specifies a custom path for build artefacts (default is ./build).\n\n--out, -o <filename>: Specifies the output filename.\n\n-emit-llvm <filename>: Writes the generated LLVM IR to the specified directory.\n\n--debug, -d: Include debug symbols in the executable artefact, and disable optimizations.\n\n--link <filename...>, -l <filename...>: Specifies the object files to include in linking.\n\n--no-specialize, -n: Do not create specialized values for literals."

using namespace std;
typedef struct configuration {
    optional<vector<string>> src_files;
    optional<string> help;
    optional<string> verbose;
    optional<optional<string>> main;
    optional<optional<string>> build_dir;
    optional<optional<string>> out;
    optional<vector<string>> link_objects;
    optional<optional<string>> emit_llvm;          // may be specified as just a flag
    optional<string> no_specialize;
    optional<string> debug;
} configuration_t;

#endif //TYTHON_CONFIG_H
