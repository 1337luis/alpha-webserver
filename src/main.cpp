/**
 * Alpha WebServer - Custom HTTP Web Server implementation
 * 
 * @author Luis Santos <luis1337@outlook.es>
 * @date 2024-04-06
 */

#include <iostream>

#include "lib/tools/Logger.h"
#include "lib/http/Server.h"
#include "lib/http/DefaultRequestHandler.h"


#include "lib/http/Request.h"

int main( int argc, char* argv[] )
{
    Http::DefaultRequestHandler response_handler;
    Http::Server *server = new Http::Server( "0.0.0.0", 8080, &response_handler );

    server->start();

    delete server;

    return 0;
}