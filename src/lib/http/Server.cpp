/**
 * Http server class implementation file
 * 
 * https://www.ibm.com/docs/en/zos/2.4.0?topic=functions-bind-bind-name-socket
 * 
 * @author Luis Santos <luis1337@outlook.es>
 * @date 2024-04-06
 */
#include "Server.h"
#include "../tools/Logger.h"

namespace Http
{
    /**
     * 
     */
    Server::Server( std::string ip_address, int port, IRequestHandler *request_handler )
    {
        this->ip_address = ip_address;
        this->port = port;
        this->request_handler = request_handler;

        this->m_address.sin_addr.s_addr = inet_addr( ip_address.c_str() ); // INADDR_ANY?
        this->m_address.sin_port = htons( port );
        this->m_address.sin_family = AF_INET;

        // Create socket file descriptor
        this->connection_socket = socket( AF_INET, SOCK_STREAM, 0 );
        
        const int enableReuseAddr = 1;
        setsockopt(this->connection_socket, SOL_SOCKET, SO_REUSEADDR, &enableReuseAddr, sizeof( int ) );
        setsockopt(this->connection_socket, SOL_SOCKET, SO_REUSEPORT, &enableReuseAddr, sizeof( int ) );

        // Assign a name to the socket
        if( bind( this->connection_socket, ( struct sockaddr * )&this->m_address, sizeof( this->m_address ) ) != 0 )
        {
            this->isNameAssigned = false;
            Tools::Logger::Error( "Cannot assign a name to the socket" );
        }
    }

    /**
     * 
     */
    Server::~Server()
    {
        Tools::Logger::Info( "Closing server..." );

        close( this->client_socket );
        close( this->connection_socket );
    }

    /**
     * 
     */
    void Server::start()
    {
        if( this->isNameAssigned )
        {
            Tools::Logger::Info( "Starting HTTP Server in " + ip_address + ":" + std::to_string( port ) + "..." );

            // Mark the socket as a passive socket (Used to accept incoming connection requests with accept)
            if( listen( this->connection_socket, HTTP_SERVER_N_QUEUE_CONNECTIONS ) == 0 )
            {
                Tools::Logger::Success( "Listening on " + this->ip_address + ":" + std::to_string( port ) );
                this->acceptConnection();

            } else {
                Tools::Logger::Error( "Cannot listen on " + this->ip_address + ":" + std::to_string( port ) );
            }
        }
    }

    /**
     * 
     */
    void Server::acceptConnection()
    {
        socklen_t client_len = sizeof( this->m_address );
        std::cout << std::endl << std::endl;

        // Start accept loop
        while( this->isListening )
        {
            // Accept is blocking the thread work until a connection is made
            this->client_socket = accept( this->connection_socket, ( struct sockaddr * )&this->m_address, &client_len );
            this->processRequest();
        }
    }

    /**
     * 
     */
    void Server::processRequest()
    {
        // Buffer for receiving request headers
        char *buffer = new char[ 2048 ];

        // Read the headers to the buffer
        read( this->client_socket, buffer, 2048 );

        std::cout << buffer << std::endl;
        
    }
}