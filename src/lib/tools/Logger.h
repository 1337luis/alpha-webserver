/**
 * Logger class header file
 * 
 * @author Luis Santos <luis1337@outlook.es>
 * @date 2024-04-06
 */

#ifndef H_TOOLS_LOGGER
#define H_TOOLS_LOGGER

#include <iostream>
#include <string>
#include <ctime>
#include <fstream>

#define LOGGER_USE_FILE_LOG true
#define LOGGER_USE_DISPLAY_LOG true
#define LOGGER_DISPLAY_COLORS true
#define LOGGER_OUTPUT_FILE "events.log"

#define LOGGER_MSG_ERROR_HEADER "[ERROR] "
#define LOGGER_MSG_INFO_HEADER "[INFO] "
#define LOGGER_MSG_SUCCESS_HEADER "[OK] "
#define LOGGER_MSG_WARNING_HEADER "[WARNING] "

#if LOGGER_DISPLAY_COLORS
    #define LOGGER_MSG_ERROR_COLOR "\033[31m"
    #define LOGGER_MSG_INFO_COLOR "\033[34m"
    #define LOGGER_MSG_SUCCESS_COLOR "\033[32m"
    #define LOGGER_MSG_WARNING_COLOR "\033[33m"
    #define LOGGER_MSG_DEFAULT_COLOR "\033[39m"
#else
    #define LOGGER_MSG_ERROR_COLOR ""
    #define LOGGER_MSG_INFO_COLOR ""
    #define LOGGER_MSG_SUCCESS_COLOR ""
    #define LOGGER_MSG_WARNING_COLOR ""
    #define LOGGER_MSG_DEFAULT_COLOR ""
#endif

#define LOGGER_N_STDOUT 1
#define LOGGER_N_ERROUT 2

namespace Tools
{
    class Logger
    {
    public:
        static int Error( std::string message );
        static int Info( std::string message );
        static int Success( std::string message );
        static int Warning( std::string message );

        static int Log( std::string message );
        static int Log( std::string message, int stdoutn );
        static int Log( std::string message, int stdoutn, std::string color_string );

    private:
        static void FileLog( std::string message );
    };
}

#endif