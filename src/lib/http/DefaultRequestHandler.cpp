/**
 * Default Request Handler class implementation file
 * 
 * @author Luis Santos <luis1337@outlook.es>
 * @date 2024-04-06
 */

#include "DefaultRequestHandler.h"

namespace Http
{
    /**
     * Get response
     * 
     * @return Response
     */
    Response DefaultRequestHandler::getResponse()
    {
        return this->response; // segfault
    }

    /**
     * Process actual request
     * 
     * @param Request request
     */
    void DefaultRequestHandler::processRequest( Request request )
    {
        this->request = &request;
        this->response = Response::fromFile( this->request->getPath() );;
    }
}