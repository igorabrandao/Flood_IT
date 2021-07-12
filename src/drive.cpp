/**
 * Flood it app runner
 */
#include <iostream>
#include "FloodIt.h"

using namespace std;

/**
 * Main function, project starts here
 */
int main()
{
    int boardSize = 14;

    /* ---------------------------- [ Test Matrix class ] ---------------------------- */

    // Create new Flood-it game
    FloodIt floodIt(boardSize);

    // Initialize the game
    floodIt.initGame();

    // Print the current board
    floodIt.printBoard();

    /* ============================================================================== */

    // Finish the program
    cout << "Finished successfully!\n";
    return EXIT_SUCCESS;
}
