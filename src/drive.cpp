/**
 * Flood it app runner
 */
#include <iostream>

// Project dependencies
#include "FloodIt.h"
#include "GameInterface.h"

using namespace std;

/**
 * Main function, project starts here
 */
int main()
{
    int boardSize = 14;

    /* ------------------------ [ Flood-it initialization ] ------------------------- */

    // Create new Flood-it game instance
    FloodIt floodIt(boardSize);

    /* ============================================================================== */

    /* -------------------------- [ GUI & input handler ] --------------------------- */

    // Handle the main menu input
    Input input;
    input.inputMainMenu(&floodIt);
    
    /* ============================================================================== */

    // Finish the program
    cout << "Finished successfully!\n";
    return EXIT_SUCCESS;
}
