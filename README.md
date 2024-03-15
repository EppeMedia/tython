# Tython
An experimental typed Python compiler.


# Installation
There are three prerequisite dependencies to be installed before you can build this project:
1. ```spdlog```
2. ```llvm```
3. ```clang```

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

# Building
To build the tython compiler, you can simply run cmake:
```
cd build && cmake ..
```

# Using the compiler

```
USAGE: tython <src...> <options>

Where <src...> are the space-separated (relative) paths to the Python source files.

OPTIONS:

--help, -?, -🤔: Display a help message and exit.

--verbose, -v: Print more messages to STD out.

--out, -o <filename>: Specifies the output filename.

-emit-llvm <filename>: Writes the generated LLVM IR to the specified file.

--debug, -d: Include debug symbols in the executable artefact.

--link <filename...>, -l <filename...>: Specifies the object files to include in linking.

--no-entry : specifies that the entry point of the executable artefact is in the specified object files (see --link).
```
