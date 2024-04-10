/**
 * FileSystem abstraction class header file
 * 
 * @author Luis Santos <luis1337@outlook.es>
 * @date 2024-04-10
 */

#ifndef H_TOOLS_FILESYSTEM
#define H_TOOLS_FILESYSTEM

#include <string>
#include <unistd.h>

#include <fstream>
#include <sstream>

#include <sys/stat.h>
#include <experimental/filesystem>

namespace Tools
{
    class FileSystem
    {
    public:
        static std::string getCurrentPath();
        static std::string fileGetContents( std::string file_path );
        
        static bool fileExists( std::string file_path );
        static bool isDirectory( std::string path );
        static bool isRegularFile( std::string path );
        static bool isSymLink( std::string path );
    };
}

#endif