/**
 * Response class implementation file
 * 
 * @author Luis Santos <luis1337@outlook.es>
 * @date 2024-04-06
 */

#include "Response.h"

namespace Http
{
    Response::Response()
    {
        final_content = "HTTP/1.1 200 Ok\nServer:alphaWebServer\nContent-Type: text/html\nContent-Length: 14\n\n<h1>Hola!</h1>";
    }

    Response::~Response()
    {
        
    }

    int Response::length()
    {
        return final_content.length() * sizeof( char );
    }

    const char* Response::to_string()
    {
        return final_content.c_str();
    }

    Response Response::fromFile( std::string file_path )
    {
        Response r;
        std::string base_path = Tools::FileSystem::getCurrentPath() + "/htdocs";

        if( Tools::FileSystem::fileExists( base_path + file_path ) )
        {
            std::string file_content = Tools::FileSystem::fileGetContents( base_path + file_path );

            // Build request content
            r.final_content = "HTTP/1.1 200 Ok\nServer:alphaWebServer\nContent-Type: text/html\nContent-Length: " + std::to_string( file_content.length() );
            r.final_content.append("\n\n" + file_content);
        } else {
            r.final_content = "HTTP/1.1 404 Not found\nServer:alphaWebServer\nContent-Type: text/html\nContent-Length: 31\n\n<h1>Error 404. Not found</h1>";
        }
        
        return r;
    }

    Response Response::fromStatusCode( int status_code )
    {

    }
}