/**
 * FileSystem abstraction class implementation file
 * 
 * @author Luis Santos <luis1337@outlook.es>
 * @date 2024-04-10
 */

#include "FileSystem.h"

#define MAX_PATH_LENGTH 256

namespace Tools
{
    /**
     * Returns the current working path
     * 
     * @return std::string Current path
     */
    std::string FileSystem::getCurrentPath()
    {
        char buffer[ MAX_PATH_LENGTH ];
        
        return ( getcwd( buffer, sizeof( buffer ) ) ? 
            std::string( buffer ) : 
            std::string( "" ) 
        );
    }

    /**
     * Gets the full content of the specified filepath
     * 
     * @param string file_path Path to file
     * @return File content
     */
    std::string FileSystem::fileGetContents( std::string file_path )
    {
        std::stringstream str_stream;
        std::ifstream file( file_path, std::ios::in );
        std::string file_content;

        if( file.is_open() )
        {
            str_stream << file.rdbuf();
            file_content = str_stream.str();
        } else {
            file_content = "";
        }

        return file_content;
    }

    /**
     * Check if file exists
     * 
     * @param string file_path Path to the file
     * @return bool
     */
    bool FileSystem::fileExists( std::string file_path )
    {
        //std::experimental::filesystem::exists(file_path);
        struct stat buffer;

        return ( stat( file_path.c_str(), &buffer ) == 0 );
    }

    /**
     * Check if a path is a directory
     * 
     * @param string path Directory path
     * @return bool
     */
    bool FileSystem::isDirectory( std::string path )
    {
        return std::experimental::filesystem::is_directory( path );
    }

    /**
     * Check if a file is a regular file
     * 
     * @param string path File path
     * @return bool
     */
    bool FileSystem::isRegularFile( std::string path )
    {
        return std::experimental::filesystem::is_regular_file( path );
    }

    /**
     * Check if a file is a symbolic link
     * 
     * @param string path File path
     * @return bool
     */
    bool FileSystem::isSymLink( std::string path )
    {
        return std::experimental::filesystem::is_symlink( path );
    }
}