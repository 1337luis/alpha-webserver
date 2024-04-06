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
     * Initialize server parameters and set some socket options to reuse addresses on process restart
     */
    Server::Server( std::string ip_address, int port, IRequestHandler *request_handler )
    {
        this->ip_address = ip_address;
        this->port = port;
        this->request_handler = request_handler;

        this->m_address.sin_addr.s_addr = inet_addr( ip_address.c_str() );
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
     * Destroy the server closing the pointers to client and connection socket FDs
     */
    Server::~Server()
    {
        Tools::Logger::Info( "Closing server..." );

        close( this->client_socket );
        close( this->connection_socket );
    }

    /**
     * Start the server if the socket has a name. Prepare it to listen
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
                this->acceptConnections();

            } else {
                Tools::Logger::Error( "Cannot listen on " + this->ip_address + ":" + std::to_string( port ) );
            }
        }
    }

    /**
     * Loop for:
     *  Acept a connection from a client, create a socket for it, process it and answer.
     * 
     * TODO: Allow ending loop with a keystroke
     */
    void Server::acceptConnections()
    {
        socklen_t client_len = sizeof( this->m_address );
        std::cout << std::endl << std::endl;

        // Start accept loop
        while( this->isListening )
        {
            // Accept is blocking the thread work until a connection is made
            this->client_socket = accept( this->connection_socket, ( struct sockaddr * )&this->m_address, &client_len );
            this->processRequest();
            this->sendResponse();
        }
    }

    /**
     * Reads the client requests and processes it with the specified RequestHandler
     */
    void Server::processRequest()
    {
        // Buffer for receiving request headers, 2048 MAX GET Request size
        char *buffer = new char[ 2048 ];

        // Read the headers to the buffer
        read( this->client_socket, buffer, 2048 );

        // Build request
        Request request( buffer );

        // Send request to the request handler
        this->request_handler->processRequest( request );
    }

    /**
     * Send response to the client socket and close it
     */
    void Server::sendResponse()
    {
        // Get processed request
        Response response = this->request_handler->getResponse();

        // Write response to the socket (Send to the client)
        write( this->client_socket, response.to_string(), response.length() );

        // Close conection to client
        close( this->client_socket );
    }
}