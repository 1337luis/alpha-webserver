/**
 * Request class header file
 * 
 * @author Luis Santos <luis1337@outlook.es>
 * @date 2024-04-06
 */

#ifndef H_HTTP_REQUEST
#define H_HTTP_REQUEST

#include <unordered_map>
#include <string>
#include <sstream>

namespace Http
{
    class Request
    {
    public:
        Request( const char* request_str );
        std::string getPath();
        std::string getVerb();
        std::string getHeader( std::string name );

    private:
        std::string verb, path, http_version;
        std::unordered_map<std::string, std::string> request_headers;
    };
}

#endif

/*
        GET /ruta HTTP/1.1
        Host: localhost:8080
        Connection: keep-alive
        Cache-Control: max-age=0
        sec-ch-ua: "Google Chrome";v="123", "Not:A-Brand";v="8", "Chromium";v="123"
        sec-ch-ua-mobile: ?0
        sec-ch-ua-platform: "Windows"
        DNT: 1
        Upgrade-Insecure-Requests: 1
        User-Agent: Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/123.0.0.0 Safari/537.36
        Accept: text/html,application/xhtml+xml,application/xml;q=0.9,image/avif,image/webp,image/apng,...
        Sec-Fetch-Site: none
        Sec-Fetch-Mode: navigate
        Sec-Fetch-User: ?1
        Sec-Fetch-Dest: document
        Accept-Encoding: gzip, deflate, br, zstd
        Accept-Language: es-ES,es;q=0.9,ro-RO;q=0.8,ro;q=0.7
        */