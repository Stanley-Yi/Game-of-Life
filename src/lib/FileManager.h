#pragma once
#include <cstdio>
#include <iostream>
#include <stdexcept>
#include <fstream>

#ifndef FileManager_h
#define FileManager_h

/**
* \file FileManager.h
* \brief This header used for read file safely.
* \ingroup utilities
*/
namespace game
{

/**
* \brief The class of FileManager used to read file.
*/

    class FileManager
    {
    private:
        FILE *f;

    public:
        FileManager(std::string fileName);

        ~FileManager();

        bool getData(char &);
    };
    

} // end namespace

#endif

