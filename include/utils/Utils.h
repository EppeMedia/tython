//
// Created by bruh on 14-11-22.
//

#ifndef CROSSOVER_UTILS_H
#define CROSSOVER_UTILS_H

#include <fstream>
#include <map>
#include <vector>
#include "../../config.h"
#include "../model/Variable.h"

using namespace std;

namespace utils {

    typedef struct configuration {
        std::vector<std::string> src_files;
        bool help;
        bool verbose;
        std::string out;
        std::vector<std::string> link_objects;
        std::string emit_llvm;
        bool debug;
    } configuration_t;

    /**
     * auxilliary function used to generate nested substructs recursively
     * @param ancestorsPtr
     * @param structure
     * @return the string of structs
     */
    string generateSubStruct(string* ancestorsPtr, Variable* structure);

    /**
     * main function for generating structs, creates a cpp header file with generated structs based on the provided
     * DataTree vector
     * @param symbol_table
     */
    std::string generateStructs(const std::string& source, const map<string, Variable*>& symbol_table, const std::string& program_id);

    /**
     * Parse the program arguments into a configuration_t struct.
     *
     * @param argc The argument count.
     * @param argv The argument array.
     * @return Returns a configuration_t struct based on the specified program arguments.
     */
    configuration_t getConfiguration(int argc, char** argv);

    /**
     * run system command and get result in an std::string
     *
     * @param cmd
     * @return
     */
    string exec(const string& cmd);

    /**
     * JAVA-like split function for strings
     * @param s
     * @param delimiter
     * @return
     */
    vector<string> split(string& s, string delimiter);

    /**
     * Extract global and local text symbols from nm output
     * @param input
     * @return
     */
    vector<string> extractTextSymbols(string& input);


    /**
     * Extract program name from program path
     * @param input
     * @return
     */
    string extractProgramNameFromPath(string path);
};


#endif //CROSSOVER_UTILS_H
