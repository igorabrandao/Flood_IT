/**
 * Flood it app runner
 */
#include <iostream>

// Project dependencies
#include "FloodIt.h"
#include "Input.h"
#include "GUI.cpp"

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

    // Print the main menu
    GUI::printMainMenu();

    // Handle the main menu input
    Input input;
    input.inputMainMenu(&floodIt);
    
    /* ============================================================================== */

    // Finish the program
    cout << "Finished successfully!\n";
    return EXIT_SUCCESS;
}
