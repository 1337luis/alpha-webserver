/**
 * Response class implementation file
 * 
 * @author Luis Santos <luis1337@outlook.es>
 * @date 2024-04-06
 */

#include "Response.h"

namespace Http
{
    /**
     * Return HTTP hello world by default. For testing purposes
     */
    Response::Response()
    {
        final_content = "HTTP/1.1 200 Ok\nServer:alphaWebServer\nContent-Type: text/html\nContent-Length: 14\n<h1>Hola!</h1>";
    }

    Response::~Response()
    {
        
    }

    /**
     * Returns the size of the actual content
     * 
     * TODO: Change return type to ulong
     * 
     * @return int Content Size (Casted from unsigned long)
     */
    int Response::length()
    {
        return final_content.length() * sizeof( char );
    }

    /**
     * Returns the content as c string
     * 
     * @return const char * Content
     */
    const char* Response::to_string()
    {
        return final_content.c_str();
    }

    /**
     * Generates a response from file
     * 
     * @param string file_path File to load
     * @return Response
     */
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
            //r.final_content = "HTTP/1.1 404 Not found\nServer:alphaWebServer\nContent-Type: text/html\nContent-Length: 31\n\n<h1>Error 404. Not found</h1>";
            r = Response::fromStatusCode( 404 );
        }
        
        return r;
    }

    /**
     * Generates a response from status code (if not implemented by web app)
     * 
     * @param int status_code HTTP Status Code
     * @return Response
     */
    Response Response::fromStatusCode( int status_code )
    {
        Response r;
        std::string path = Tools::FileSystem::getCurrentPath() + "/htdocs/" + std::to_string( status_code ) + ".html";

        if( Tools::FileSystem::fileExists( path ) )
        {
            std::string file_content = Tools::FileSystem::fileGetContents( path );

            // Build request content
            // TODO: Respuesta acorde con el código de estado. No es lógico que un 404 diga "OK"
            r.final_content = "HTTP/1.1 " + std::to_string( status_code ) + " Ok\nServer:alphaWebServer\nContent-Type: text/html\nContent-Length: " + std::to_string( file_content.length() );
            r.final_content.append("\n\n" + file_content);
        } else {
            r.final_content = "HTTP/1.1 404 Not found\nServer:alphaWebServer\nContent-Type: text/html\nContent-Length: 31\n\n<h1>Error 404. Not found</h1>";
        }
        
        return r;
    }
}