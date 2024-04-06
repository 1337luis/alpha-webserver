/**
 * Main file
 * 
 * @author Luis Santos <luis1337@outlook.es>
 * @date 2024-04-06
 */

#include <iostream>
#include "lib/tools/Logger.h"
#include "lib/http/Server.h"

int main( int argc, char* argv[] )
{
    Http::Server *server = new Http::Server( "0.0.0.0", 8080, nullptr );
    server->start();

    delete server;

    return 0;
}