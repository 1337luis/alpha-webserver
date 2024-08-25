/**
 * Alpha WebServer - Custom HTTP Web Server implementation
 * 
 * @author Luis Santos <luis1337@outlook.es>
 * @date 2024-04-06
 */

#include <iostream>

#include "lib/http/Server.h"
#include "lib/http/DefaultRequestHandler.h"

int main( int argc, char* argv[] )
{
    // Create handler
    Http::DefaultRequestHandler response_handler;

    // Create server and start loop
    Http::Server *server = new Http::Server( "0.0.0.0", 8080, &response_handler );
    server->start();

    // Delete server
    delete server;

    // Return status code
    return 0;
}