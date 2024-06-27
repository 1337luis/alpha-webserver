/**
 * Dot conf configuration file reader header file
 * 
 * @author Luis Santos <luis1337@outlook.es>
 * @date 2024-04-10
 */

#ifndef H_CONFIG_DOT_CONF_FILE
#define H_CONFIG_DOT_CONF_FILE

#include <unordered_map>
#include <string>

#define DOT_CONF_ERROR_500 "500.html"
#define DOT_CONF_ERROR_404 "404.html"
#define DOT_CONF_DIRECTORY_INDEX "index.html index.htm index.shtml"

namespace Config
{
    class DotConfFile
    {
        DotConfFile( std::string path );
        ~DotConfFile();
        
        std::string get( std::string key );
        void set( std::string key, std::string value );

    private:
        std::unordered_map<std::string, std::string> configuration;
    };
}
#endif