#include "FileManager.h"


namespace game {

    FileManager::FileManager(std::string fileName) 
    {
        f = std::fopen(fileName.c_str(), "rw");

        if(! f) {
            throw std::runtime_error("Failed to open file " + fileName);
        }
        std::cout << "File " + fileName + " opened." << std::endl;
    }

    FileManager::~FileManager()
    {
        if (f)
        {
            std::fclose(f);
            std::cout << "File closed." << std::endl;
        }
    }

    bool FileManager::getData(char &c)
    {

        if (std::fscanf(f, "%c", &c) != EOF)
        {
            return true;
        }
        else
        {
            return false;
        }
    }


}