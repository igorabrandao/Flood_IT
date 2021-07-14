#ifndef FILE_HPP
#define FILE_HPP

// ***************************************************
// ** Implements the functions related to File
// ***************************************************
#include <stdio.h>
#include "config.h"

#ifdef __linux__
#include <unistd.h>
#else
inline int access(const char *pathname, int mode)
{
     return _access(pathname, mode);
}
#endif

using namespace std;

// ***************************************************
// ** Functions
// ***************************************************

namespace File
{
     /**
      * Function to check the config file
      */
     int checkConfigFile(const char *fname)
     {
          //return (access(fname, F_OK) != -1 ? 1 : 0);
     }

     /**
      * Function to generate the game config file
      */
     void createConfigFile(const char *fname, CONFIG *config_)
     {
          /* Criação do arquivo e modo de escrita */
          FILE *fp = fopen(fname, "w+");

          /* Escrevendo as configurações no arquivo */
          fprintf(fp, "difficultLevel = %i\n", config_->difficultLevel);
          fprintf(fp, "maxNPlay = %i\n", config_->maxNPlay);
          fprintf(fp, "boardSize = %i\n", config_->boardSize);

          // Fechamento do arquivo
          fclose(fp);
     }
}

#endif