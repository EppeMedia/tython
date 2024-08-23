# Tython

An experimental type-shifting Python compiler. Initially developed for running performance experiments for the MSc. thesis of Manzi Aimé Ntagengerwa (https://manzi-it.com/file/resume/tython.pdf).

# Installation

There are four prerequisite dependencies to be installed before you can build this project:

1. ```spdlog```
2. ```llvm```
3. ```clang```
4. ```gperftools```

Additionally, make sure you have a Java runtime environment (```JRE```) installed.

We provide a short overview for installation of these dependencies on Ubuntu:
```
apt install libspdlog-dev
```
```
bash -c "$(wget -O - https://apt.llvm.org/llvm.sh)"
```
```
apt install clang
```
```
apt install libgoogle-perftools-dev
```
You will need sudo permissions for these commands.

# Building

Tython uses ANTLR for lexing and parsing. The build script expects an ANTLR 4.11.1 JAR at `./thirdparty/antlr/antlr-4.11.1-complete.jar`. If this is not placed there by the build script, please download the JAR file manually (https://github.com/antlr/website-antlr4/tree/gh-pages/download) and place it in the specified path.

The compiler depends on an associated runtime library to which it links its artefacts. The source code is found in the ./lib directory. To build the Tython compiler (and its dependencies), you can simply run cmake:
```
mkdir -p build && cd build && cmake ..
```

# Using the compiler

You must manually link to the Tython runtime library with the `--link` option to compile any interesting program.

Tython implements a few utility modules in Python. These modules can be found in ./tython_std. The current version of tython unfortunately requires this exact directory to be present in the working directory of wherever the compiler is invoked.

Future versions of Tython will have an alternative solutions to these awkward usage requirements. This will probably involve pre-building the Tython runtime and the STD modules and either dynamically linking artefacts to them or somehow packaging them with the compiler.

```
USAGE: tython <src...> <options>

Where <src...> are the space-separated (relative) paths to the tython source files. Does not support directories.

OPTIONS:

--help, -?, -🤔: Display this help message and exit.

--version: Display the build version and exit.

--verbose, -v: Print more messages to STD out.

--main, -m <src>: Specifies the artefact entry point. If the target artefact is an executable, exactly one source file must be specified as the entry point. Note: if the specified source file is also included in the list of sources (the first compiler argument <src...>), it is not compiled twice, and its order or inclusion is still the order of inclusion as specified in the first argument.

--build-dir, -b <directory>: Specifies a custom path for build artefacts (default is ./build).

--out, -o <filename>: Specifies the output filename.

-emit-llvm <filename>: Writes the generated LLVM IR to the specified directory.

--debug, -d: Include debug symbols in the executable artefact, and disable optimizations.

--link <filename...>, -l <filename...>: Specifies the object files to include in linking.

--no-specialize, -n: Do not create specialized values for literals.

--no-guards: Do not generate type guards. This option is only applied if the --no-specialize flag is also set.
```
