/**
 * Flood it app runner
 */
#include <iostream>
#include "FloodIt.h"
#include "GUI.hpp"

using namespace std;

/**
 * Main function, project starts here
 */
int main()
{
    int boardSize = 14;

    /* ------------------------ [ Flood-it initialization ] -------------------------- */

    // Create new Flood-it game
    FloodIt floodIt(boardSize);

    // Initialize the game
    floodIt.initGame();

    // Print the current board
    GUI::printBoard(floodIt.getBoard());

    /* ============================================================================== */

    // Finish the program
    cout << "Finished successfully!\n";
    return EXIT_SUCCESS;
}
