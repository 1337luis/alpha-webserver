/**
 * Request class header file
 * 
 * @author Luis Santos <luis1337@outlook.es>
 * @date 2024-04-06
 */

#ifndef H_HTTP_REQUEST
#define H_HTTP_REQUEST

#include <unordered_map>
#include <string>
#include <sstream>

namespace Http
{
    class Request
    {
    public:
        Request( const char* request_str );
        std::string getPath();
        std::string getVerb();
        std::string getHeader( std::string name );

    private:
        std::string verb, path, http_version;
        std::unordered_map<std::string, std::string> request_headers;
    };
}

#endif