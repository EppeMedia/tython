//
// Created by bruh on 14-11-22.
//

#ifndef CROSSOVER_UTILS_H
#define CROSSOVER_UTILS_H

#include <fstream>
#include <map>
#include <vector>
#include <ParserRuleContext.h>
#include "../../config.h"
#include "ir/TythonModule.h"

using namespace std;

namespace utils {

    /**
     * Parse the program arguments into a configuration_t struct.
     *
     * @param argc The argument count.
     * @param argv The argument array.
     * @return Returns a configuration_t struct based on the specified program arguments.
     */
    configuration_t getConfiguration(int argc, char** argv);

    /**
     * Runs the specified command in a system shell, and waits for it to terminate.
     *
     * @param cmd The shell command to run.
     * @return Returns the command result code.
     */
    int exec(const string& cmd);

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
     * Gets the object name from the specified file path.
     * @param path The path from which to get the object name.
     * @return The object name from the given path.
     */
    std::string get_objectname(std::string& path);

    /**
     * Logs the specified message with source file line info.
     * @param module The source file module.
     * @param ctx The current parser context.
     * @param message The message to log.
     */
    void log_warn(const TythonModule* module, antlr4::ParserRuleContext* ctx, const std::string& message);

};


#endif //CROSSOVER_UTILS_H
