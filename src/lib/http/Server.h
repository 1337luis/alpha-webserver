/**
 * Http server class header file
 * 
 * 1.- Open the socket at the specified port (Initialize and bind socket)
 * 2.- Start listeing to the socket (Listen)
 * 3.- On client request (acept), process request (Read)
 * 4.- Determine appropiate response
 * 5.- Build response
 * 6.- Send response back (Write)
 * 7.- Close sockets
 * 
 * @author Luis Santos <luis1337@outlook.es>
 * @date 2024-04-06
 */

#ifndef H_HTTP_SERVER
#define H_HTTP_SERVER

#include <string>
#include <unistd.h>

#include <sys/socket.h>
#include <sys/types.h>
#include <arpa/inet.h>

#include "IRequestHandler.h"


#define HTTP_SERVER_N_QUEUE_CONNECTIONS 10

namespace Http
{
    class Server
    {
    public:
        Server( std::string ip_address, int port, IRequestHandler *request_handler );
        ~Server();
        void start();

    private:
        void acceptConnection();
        void processRequest();

        int connection_socket;
        int client_socket;
        bool isNameAssigned = true;
        bool isListening = true;

        struct sockaddr_in m_address;
        std::string ip_address;
        int port;

        IRequestHandler *request_handler;
    };
}

#endif