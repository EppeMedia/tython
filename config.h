//
// Created by manzi on 6/20/23.
//
#ifndef TYTHON_CONFIG_H
#define TYTHON_CONFIG_H

#include <optional>

#define LABEL_MAIN              "main"
#define TYTHON_VERSION          "v0.1"

// program arguments
#define FLAG_HELP               "--help"            // prints a help message and exits
#define FLAG_HELP_SHORT         "-?"
#define FLAG_HELP_UNHELPFUL     "-🤔"
#define FLAG_VERBOSE            "--verbose"         // print more messages to STD out
#define FLAG_VERBOSE_SHORT      "-v"
#define FLAG_LINK_OBJECTS       "--link"            // the object files we want to include when linking
#define FLAG_LINK_OBJECTS_SHORT "-l"
#define FLAG_EMIT_LLVM          "-emit-llvm"        // Clang-like argument to emit llvm IR to the specified directory
#define FLAG_EMIT_DEBUG         "--debug"           // Enable debug symbols in the artefact
#define FLAG_EMIT_DEBUG_SHORT   "-d"
#define FLAG_BUILD_DIR          "--build-dir"       // specify a directory for build artefacts
#define FLAG_BUILD_DIR_SHORT    "-b"
#define FLAG_OUTPUT             "--out"             // specifies the executable artefact's filename
#define FLAG_OUTPUT_SHORT       "-o"

#define MSG_HELP                "USAGE: tython <src...> <options>\n\nWhere <src...> are the space-separated (relative) paths to the tython source files. Does not support directories.\n\nOPTIONS:\n\n--help, -?, -🤔: Display this help message and exit.\n\n--verbose, -v: Print more messages to STD out.\n\n--build-dir, -d <directory>: Specifies a custom path for build artefacts (default is ./build).\n\n--out, -o <filename>: Specifies the output filename.\n\n-emit-llvm <filename>: Writes the generated LLVM IR to the specified directory.\n\n--debug, -d: Include debug symbols in the executable artefact.\n\n--link <filename...>, -l <filename...>: Specifies the object files to include in linking.\n\n--generate-structs."

using namespace std;
typedef struct configuration {
    optional<vector<string>> src_files;
    optional<string> help;
    optional<string> verbose;
    optional<optional<string>> build_dir;
    optional<optional<string>> out;
    optional<vector<string>> link_objects;
    optional<optional<string>> emit_llvm;          // may be specified as just a flag
    optional<string> debug;
} configuration_t;

#endif //TYTHON_CONFIG_H
