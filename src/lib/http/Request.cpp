/**
 * Request class implementation file
 * 
 * @author Luis Santos <luis1337@outlook.es>
 * @date 2024-04-06
 */

#include "Request.h"

namespace Http
{
    /**
     * Build request object from raw request string
     * 
     * @param const char* request_str Request headers string
     */
    Request::Request( const char* request_str )
    {
        std::stringstream ss( request_str );
        std::string line;
        int index = 0;

        // We iterate over every new line of the request
        while( std::getline( ss, line, '\n' ) )
        {
            if( index == 0 )
            {
                // HTTP Request
                std::stringstream verb_str( line );

                // Extract every part of the request
                verb_str >> verb >> path >> http_version;

            } else {
                // Request headers
                size_t pos = line.find( ':' );

                if( pos != std::string::npos )
                {
                    std::string header_name = line.substr( 0, pos );
                    std::string header_value = line.substr( pos + 1 );

                    // Remove first space after ":"
                    header_value.erase( 0, 1 );

                    request_headers[ header_name ] = header_value;
                }
            }

            index++;
        }
    }

    /**
     * Get requested path/route
     * 
     * @return std::string Path
     */
    std::string Request::getPath()
    {
        return this->path;
    }

    /**
     * Get verb of the request
     * 
     * @return std::string Verb
     */
    std::string Request::getVerb()
    {
        return this->verb;
    }

    /**
     * Get specific header of the request
     * 
     * @param std::string name Name of the header
     * @return std::string Value of the header (if exists)
     */
    std::string Request::getHeader( std::string name )
    {
        return this->request_headers[ name ];
    }
}