/**
 * Response class header file
 * 
 * @author Luis Santos <luis1337@outlook.es>
 * @date 2024-04-06
 */

#ifndef H_HTTP_RESPONSE
#define H_HTTP_RESPONSE

#include <string>
#include <unordered_map>

#include "../tools/FileSystem.h"

namespace Http
{
    class Response
    {
    public:
        Response();
        ~Response();

        int length();
        const char* to_string();

        static Response fromFile( std::string file_path );
        static Response fromStatusCode( int status_code );

    private:
        int status_code, content_length;
        bool isPlainContent = true;

        std::string final_content, content_type, content_type_charset, plain_content;

        std::unordered_map<std::string, std::string> headers = {
            { "Server", "alpha WebServer" },
            { "Content-Type", "text/html; charset=UTF-8" },
            { "Content-Length", "14"}
        };

    };
}

#endif