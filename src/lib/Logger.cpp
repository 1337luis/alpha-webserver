/**
 * Logger class implementation file
 * 
 * @author Luis Santos <luis1337@outlook.es>
 * @date 2024-04-06
 */

#include "Logger.hpp"

namespace Tools
{
    /**
     * Registers an error an sends it to the error output
     * 
     * @param std::string message Message to register or show
     */
    int Logger::Error( std::string message )
    {
        return Logger::Log( LOGGER_MSG_ERROR_HEADER + message, LOGGER_N_ERROUT, LOGGER_MSG_ERROR_COLOR );
    }

    /**
     * Registers a generic message and sends it to the standard output
     * 
     * @param std::string message Message to register or show
     */
    int Logger::Info( std::string message )
    {
        return Logger::Log( LOGGER_MSG_INFO_HEADER + message, LOGGER_N_STDOUT, LOGGER_MSG_INFO_COLOR );
    }

    /**
     * Registers a success message and sends it to the standard output
     * 
     * @param std::string message Message to register or show
     */
    int Logger::Success( std::string message )
    {
        return Logger::Log( LOGGER_MSG_SUCCESS_HEADER + message, LOGGER_N_STDOUT, LOGGER_MSG_SUCCESS_COLOR );
    }

    /**
     * Registers a warning message and sends it to the standard output
     * 
     * @param std::string message Message to register or show
     */
    int Logger::Warning( std::string message )
    {
        return Logger::Log( LOGGER_MSG_WARNING_HEADER + message, LOGGER_N_STDOUT, LOGGER_MSG_WARNING_COLOR );
    }

    /**
     * Registers a message, changing colors and type of output
     * 
     * @param std::string message Message to register or show
     * @param int stdoutn Type of output (LOGGER_N_STDOUT|LOGGER_N_ERROUT)
     * @param std::string color_string Color of the output
     */
    int Logger::Log( std::string message, int stdoutn, std::string color_string )
    {
        std::time_t now = std::time( nullptr );
        char timeString[ 64 ];
        std::strftime( timeString, sizeof( timeString ), "[%Y-%m-%d %H:%M:%S] ", std::localtime( &now ) );

        if( LOGGER_USE_DISPLAY_LOG )
        {
            if( stdoutn == LOGGER_N_STDOUT )
            {
                std::cout << color_string << timeString << message << LOGGER_MSG_DEFAULT_COLOR << std::endl;
            } else {
                std::cerr << color_string << timeString << message << LOGGER_MSG_DEFAULT_COLOR << std::endl;
            }
        }

        // If we need to log to a file
        if( LOGGER_USE_FILE_LOG )
        {
            Logger::FileLog( timeString + message );
        }
    }

    /**
     * Simplification of Logger::Log, defaulting color_string to the default system color
     * 
     * @param std::string message Message to register or show
     * @param int stdoutn Type of output (LOGGER_N_STDOUT|LOGGER_N_ERROUT)
     */
    int Logger::Log( std::string message, int stdoutn )
    {
        return Logger::Log( message, stdoutn, "" );
    }

    /**
     * Simplification of Logger::Log, defaulting color_string to the default system color
     * and the output type to the standard output
     * 
     * @param std::string message Message to register or show
     */
    int Logger::Log( std::string message )
    {
        return Logger::Log( message, LOGGER_N_STDOUT, "" );
    }

    /**
     * Saves log line to a file
     * 
     * @param std::string message Message to register or show
     */
    void Logger::FileLog( std::string message )
    {
        std::ofstream logfile( LOGGER_OUTPUT_FILE, std::ios_base::app );

        if( logfile.is_open() )
        {
            logfile << message << std::endl;
            logfile.close();
        } else {
            Logger::Warning( "Cannot open log file " );
        }
    }
}