/**
 * Response class header file
 * 
 * @author Luis Santos <luis1337@outlook.es>
 * @date 2024-04-06
 */

#ifndef H_HTTP_RESPONSE
#define H_HTTP_RESPONSE

#include <string>
#include <unordered_map>

namespace Http
{
    class Response
    {
    public:
        Response();
        ~Response();

        int length();
        const char* to_string();

        Response fromFile( std::string file_path );
    private:
        int status_code, content_length;
        std::string content_type, content_type_charset;

        const std::unordered_map<int, const char*> httpStatusMessages = {
            { 100, "Continue" },
            { 101, "Switching Protocols" },
            { 200, "OK" },
            { 201, "Created" },
            { 202, "Accepted" },
            { 203, "Non-Authoritative Information" },
            { 204, "No Content" },
            { 205, "Reset Content" },
            { 206, "Partial Content" },
            { 300, "Multiple Choices" },
            { 301, "Moved Permanently" },
            { 302, "Found" },
            { 303, "See Other" },
            { 304, "Not Modified" },
            { 305, "Use Proxy" },
            { 307, "Temporary Redirect" },
            { 400, "Bad Request" },
            { 401, "Unauthorized" },
            { 402, "Payment Required" },
            { 403, "Forbidden" },
            { 404, "Not Found" },
            { 405, "Method Not Allowed" },
            { 406, "Not Acceptable" },
            { 407, "Proxy Authentication Required" },
            { 408, "Request Timeout" },
            { 409, "Conflict" },
            { 410, "Gone" },
            { 411, "Length Required" },
            { 412, "Precondition Failed" },
            { 413, "Payload Too Large" },
            { 414, "URI Too Long" },
            { 415, "Unsupported Media Type" },
            { 416, "Range Not Satisfiable" },
            { 417, "Expectation Failed" },
            { 418, "I'm a teapot" },
            { 426, "Upgrade Required" },
            { 500, "Internal Server Error" },
            { 501, "Not Implemented" },
            { 502, "Bad Gateway" },
            { 503, "Service Unavailable" },
            { 504, "Gateway Timeout" },
            { 505, "HTTP Version Not Supported" }
        };

        std::unordered_map<std::string, std::string> headers = {
            { "Server", "alpha WebServer" },
            { "Content-Type", "text/html; charset=UTF-8" },
            { "Content-Length", "14"}
        };

    };
}

#endif