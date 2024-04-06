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

    }

    Response::~Response()
    {
        
    }

    int Response::length()
    {
        return 97 * sizeof( char );
    }

    const char* Response::to_string()
    {
        return "HTTP/1.1 200 Ok\nServer:alphaWebServer\nContent-Type: text/html\nContent-Length: 14\n\n<h1>Hola!</h1>";
    }

    Response Response::fromFile( std::string file_path )
    {

    }
}