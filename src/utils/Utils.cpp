//
// Created by bruh on 14-11-22.
//

#include <list>
#include "../../include/utils/Utils.h"
#include "../../include/exception/CompileException.h"
#include <spdlog/spdlog.h>

using namespace std;

namespace utils {

    /**
     * Check program arguments for presence of the specified flags.
     *
     * @param argc The program argument count.
     * @param argv The program arguments.
     * @param flags The flags to check for presence.
     * @return Returns true if any of the specified flags is present in the specified program arguments.
     */
    static optional<const std::string> hasFlag(int argc, char** argv, const std::initializer_list<std::string>& flags) {

        for (int i = 0; i < argc; ++i) {
            for (const string& flag: flags) {

                if (argv[i] == flag) {
                    return { flag };
                }
            }
        }

        return {};
    }

    /**
     * Check program arguments for presence of the specified flag.
     *
     * @param argc The program argument count.
     * @param argv The program arguments.
     * @param flag The flag to check for presence.
     * @return Returns true if the specified flag is present in the specified program arguments.
     */
    static optional<const std::string> hasFlag(int argc, char** argv, const std::string& flag) {
        return hasFlag(argc, argv, {flag});
    }

    /**
      * Get a single program argument for the given flag synonyms.
      *
      * @example If the program arguments are [arg0 arg1 --flag0 arg2 arg3 --flag1 arg4], then getFlagArguments(..., ..., { "--flag1", "-f1"}) returns [arg4].
      * Similarly, if the program arguments are [arg0 arg1 --flag0 arg2 arg3 --f1 arg4], then getFlagArgument(..., ..., { "--flag1", "-f1"}) also returns [arg4].
      * In other words, "--flag1" and "-f1" are synonyms.
      * @param argc The number of program arguments.
      * @param argv The program arguments.
      * @param flag The flag for which to collect its argument
      * @return Returns the argument for this flag, or an empty string if there is no argument or the flag is not present in the program arguments.
      */
    static optional<optional<string>> getFlagArgument(int argc, char** argv, const std::initializer_list<std::string>& flags) {

        // arguments start at index 1
        for (int i = 1; i < argc; ++i) {

            for (const std::string& flag : flags) {

                if (argv[i] == flag) {

                    if (i + 1 >= argc) {

                        spdlog::warn("No argument provided for flag {}", flag);

                        return optional<string>();
                    }

                    const std::string &arg = argv[i + 1];

                    // if the "argument" starts with a dash, we interpret it as the next flag; we warn that we expected to find an argument here.
                    if (arg[0] == '-') {

                        spdlog::warn("No argument is provided, but expected one for flag {}", flag);

                        return optional<string>();
                    }

                    return { arg };
                }
            }
        }

        return {};
    }

    /**
      * Get a single program argument for a given flag.
      *
      * @example If the program arguments are [arg0 arg1 --flag0 arg2 arg3 --flag1 arg4], then getFlagArgument(..., ..., "--flag1") returns [arg4].
      * @param argc The number of program arguments.
      * @param argv The program arguments.
      * @param flag The flag for which to collect its argument
      * @return Returns the argument for this flag, or an empty string if there is no argument or the flag is not present in the program arguments.
      */
    static optional<optional<string>> getFlagArgument(int argc, char** argv, const string& flag, bool optional = false) {
        return getFlagArgument(argc, argv, { flag });
    }

    /**
      * Get the programs arguments for the given flag synonyms.
      *
      * @example If the program arguments are [arg0 arg1 --flag0 arg2 arg3 --flag1 arg4], then getFlagArguments(..., ..., { "--flag0", "-f0"}) returns [arg2, arg3].
      * Similarly, if the program arguments are [arg0 arg1 --f0 arg2 arg3 --flag1 arg4], then getFlagArguments(..., ..., { "--flag0", "-f0"}) also returns [arg2, arg3].
      * In other words, "--flag0" and "-f0" are synonyms.
      * @param argc The number of program arguments.
      * @param argv The program arguments.
      * @param flag The flag for which to collect its arguments
      * @return Returns the arguments for this flag in-order, or an empty vector if there are no arguments or the flag is not present in the program arguments.
      */
    static optional<vector<std::string>> getFlagArguments(int argc, char** argv, const std::initializer_list<std::string>& flags) {

        // arguments start at index 1
        for (int i = 1; i < argc; ++i) {

            for (const std::string& flag : flags) {

                if (argv[i] == flag) {

                    vector<string> arguments;

                    // collect program arguments for the matched flag
                    for (int j = i + 1; j < argc; ++j) {

                        const std::string &arg = argv[j];

                        // if the "argument" starts with a dash, we interpret it as the next flag; we've gathered all params for our target.
                        if (arg[0] == '-') {
                            break;
                        }

                        arguments.push_back(arg);
                    }

                    if (arguments.empty()) {
                        spdlog::warn("No arguments provided for flag {}", flag);
                    }

                    return arguments;
                }
            }
        }

        return {};
    }

    /**
      * Get the programs arguments for a given flag.
      *
      * @example If the program arguments are [arg0 arg1 --flag0 arg2 arg3 --flag1 arg4], then getFlagArguments(..., ..., "--flag0") returns [arg2, arg3].
      * @param argc The number of program arguments.
      * @param argv The program arguments.
      * @param flag The flag for which to collect its arguments
      * @return Returns the arguments for this flag in-order, or an empty vector if there are no arguments or the flag is not present in the program arguments.
      */
    static optional<vector<string>> getFlagArguments(int argc, char** argv, const std::string& flag) {
        return getFlagArguments(argc, argv, { flag });
    }


    /**
      * Get the first programs arguments with no flag.
      *
      * @example If the program arguments are [arg0 arg1 --flag0 arg2 arg3 --flag1 arg4], then getDefaultArguments(..., ...) returns [arg0, arg1].
      * @param argc The number of program arguments.
      * @param argv The program arguments.
      * @return Returns the default program arguments in-order, or an empty vector if there are no default program arguments.
      */
    static optional<vector<string>> getDefaultArguments(int argc, char** argv) {

        if (argc < 1) {
            return {};
        }

        vector<string> arguments;

        // arguments start at index 1
        for (int i = 1; i < argc; ++i) {

            // collect default program arguments until the first flag
            const std::string& arg = argv[i];

            // if the "argument" starts with a dash, we interpret it as the next flag; we've gathered all params for our target.
            if (arg[0] == '-') {
                break;
            }

            arguments.push_back(arg);
        }

        return arguments;
    }

    configuration_t getConfiguration(int argc, char** argv) {
        return configuration_t {
            .src_files = getDefaultArguments(argc, argv),
            .help = hasFlag(argc, argv, { FLAG_HELP, FLAG_HELP_SHORT, FLAG_HELP_UNHELPFUL }),
            .verbose = hasFlag(argc, argv, { FLAG_VERBOSE, FLAG_VERBOSE_SHORT }),
            .main = getFlagArgument(argc, argv, { FLAG_MAIN, FLAG_MAIN_SHORT }),
            .build_dir = getFlagArgument(argc, argv, { FLAG_BUILD_DIR, FLAG_BUILD_DIR_SHORT }),
            .out = getFlagArgument(argc, argv, { FLAG_OUTPUT, FLAG_OUTPUT_SHORT }),
            .link_objects = getFlagArguments(argc, argv, { FLAG_LINK_OBJECTS, FLAG_LINK_OBJECTS_SHORT }),
            .emit_llvm = getFlagArgument(argc, argv, FLAG_EMIT_LLVM),
            .debug = hasFlag(argc, argv, { FLAG_EMIT_DEBUG, FLAG_EMIT_DEBUG_SHORT }),
        };
    }

    std::string exec(const string& cmd) {

        char buffer[128];

        std::string result;

        std::unique_ptr<FILE, decltype(&pclose)> pipe(popen(cmd.c_str(), "r"), pclose);

        if (!pipe) {
            throw std::runtime_error("popen() failed!");
        }

        while (fgets(buffer, 128, pipe.get()) != nullptr) {
            result += buffer;
        }

        return result;
    }

    vector<string> split(string& s, string delimiter) {
        size_t pos_start = 0, pos_end, delim_len = delimiter.length();
        string token;
        vector<string> res;

        while ((pos_end = s.find (delimiter, pos_start)) != string::npos) {
            token = s.substr (pos_start, pos_end - pos_start);
            pos_start = pos_end + delim_len;
            res.push_back (token);
        }
        res.push_back (s.substr (pos_start));
        return res;
    }

    vector<string> extractTextSymbols(string& input){
        //filter on things that have either t or T
        vector<string> completeTable = split(input, "\n");
        vector<string> result;
        for (auto & element : completeTable) {
            if (element.find(" T ") != std::string::npos) {
                result.push_back(element.substr(element.find(" T ") + 3));
            } else if ((element.find(" t ") != std::string::npos)){
                result.push_back(element.substr(element.find(" t ") + 3));
            }
        }
        return result;
    }

    std::string get_objectname(std::string& path) {

        auto pathseparator_index = path.find_last_of('/');
        auto fileextension_index = path.find(".ty", pathseparator_index);

        if (fileextension_index == std::string::npos) {
            spdlog::warn("Warning: expected file extension \".ty\" for file " + path + ". Assuming file is a valid Tython file regardless...");
        }

        fileextension_index = path.find_last_of('.');

        if (pathseparator_index == std::string::npos) {
            return path.substr(0, fileextension_index);
        }

        const auto start_index = pathseparator_index + 1;
        const auto n = fileextension_index - start_index;

        return path.substr(start_index, n);
    }

}