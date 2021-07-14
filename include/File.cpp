// ***************************************************
// ** Implements the functions related to the Game
// ** Interface class
// ***************************************************
#include "File.h"

// ***************************************************
// ** Functions
// ***************************************************

#ifdef __linux__
#include <unistd.h>
#else
inline int access(const char *pathname, int mode)
{
     return _access(pathname, mode);
}
#endif

// ***************************************************
// ** Functions
// ***************************************************

/**
 * Function to check the config file
 */
int File::checkConfigFile(const char *fname)
{
     //return (access(fname, F_OK) != -1 ? 1 : 0);
     return 0;
}

/**
 * Function to generate the game config file
 */
void File::createConfigFile(const char *fname, CONFIG *config_)
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