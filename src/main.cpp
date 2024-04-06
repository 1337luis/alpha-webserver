/**
 * Main file
 * 
 * @author Luis Santos <luis1337@outlook.es>
 * @date 2024-04-06
 */

#include <iostream>
#include "lib/Logger.hpp"

int main( int argc, char* argv[] )
{
    Tools::Logger::Info( "Hello World!" );
    Tools::Logger::Error( "Hello World!" );
    Tools::Logger::Success( "Hello World!" );
    Tools::Logger::Warning( "Hello World!" );
    Tools::Logger::Log( "Hello World!" );

    return 0;
}