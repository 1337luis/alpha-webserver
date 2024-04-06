/**
 * Request Handler interface header file
 * 
 * @author Luis Santos <luis1337@outlook.es>
 * @date 2024-04-06
 */
#ifndef H_HTTP_IREQUESTHANDLER
#define H_HTTP_IREQUESTHANDLER

#include "Request.h"

namespace Http
{
    class IRequestHandler
    {
    public:
        virtual const char * getResponse();
        virtual void setRequest( Request request );
    };
}

#endif