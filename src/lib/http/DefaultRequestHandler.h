/**
 * Default Request Handler class header file
 * 
 * @author Luis Santos <luis1337@outlook.es>
 * @date 2024-04-06
 */

#ifndef H_HTTP_DEFAULTREQUESTHANDLER
#define H_HTTP_DEFAULTREQUESTHANDLER

#include "IRequestHandler.h"

namespace Http
{
    class DefaultRequestHandler: public IRequestHandler
    {
    public:
        Response getResponse();
        void processRequest( Request request );

    private:
        Request *request;
        Response response;
    };
}

#endif