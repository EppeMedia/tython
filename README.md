# crossover
An experimental BabyCobol Compiler with C interoperability


# Installation
There are three prerequisite dependencies to be installed before you can build this project:
1. ```spdlog```
2. ```llvm```
3. ```clang```
3. ```bstd```

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
You will need root permission for these commands.

The BabyCobol Standard Library `BSTD` can be built from source and installed following the README in the official repo: https://github.com/omersayilir75/Crossover_bstd_lib.


# Building
To build the crossover compiler, you can simply run cmake:
```
cmake .
```

# Using the compiler

```
USAGE: crossover <src...> <options>

Where <src...> are the space-separated (relative) paths to the BabyCobol source files. Does not support directories.

OPTIONS:

--help, -?, -🤔: Display a help message and exit.

--verbose, -v: Print more messages to STD out.

--out, -o <filename>: Specifies the output filename.

-emit-llvm <filename>: Writes the generated LLVM IR to the specified file.

--debug, -d: Include debug symbols in the executable artefact.

--link <filename...>, -l <filename...>: Specifies the object files to include in linking.

--generate-structs, -g: If set, crossover will generate C headers for the data divisions in the BabyCobol source files and exit without compilation.

--no-entry : specifies that the entry point of the executable artefact is in the specified object files (see --link).
```

# Programming guide

## Naming

BabyCobol paragraph names are internally case-insensitive. Across the FFI, paragraph names can be accessed in lower case only. Make sure to keep this in mind. Example:
```
BabyCobol
-------------------
PROCEDURE DIVISION.
FOO.
    CALL Foo.       <-- this is fine


C
-------------------
void bar() {
    FOO();          <-- this does not work
    foo();          <-- this works
}
```

## Additional notes
Paragraphs are not hoisted. This means that a paragraph needs to be defined before it can be called.