#ifndef CONFIG_H
#define CONFIG_H

/**
 * CONFIG with available game options
 */
typedef struct config
{
    // Jogability attributes
    int difficultLevel; /* 1- Easy 2- Medium 3- hard  */
    int boardSize;      /* Custom size. Default 14 */
    int maxNPlay;       /* Default 25 */
} CONFIG;

#endif