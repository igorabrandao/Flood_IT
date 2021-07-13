/**
 * Flood it app runner
 */
#include <iostream>

// Project dependencies
#include "FloodIt.h"
#include "GUI.hpp"
#include "input.hpp"

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
    Input::inputMainMenu(floodIt);

    // Print the current board
    /*GUI::printHeader();
    GUI::printBoard(this->getBoard());
    GUI::printFooter();*/

    /* ============================================================================== */

    // Finish the program
    cout << "Finished successfully!\n";
    return EXIT_SUCCESS;
}
