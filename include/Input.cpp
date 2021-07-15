// ***************************************************
// ** Implements the functions related to Input class
// ***************************************************
#include "GameInterface.h"

// ***************************************************
// ** Functions
// ***************************************************

/**
 * Function to handle the user input
 */
int Input::handleInput(const char *prompt, int *i)
{
     int Invalid = 0;
     int EndIndex;
     char buffer[100];

     do
     {
          if (Invalid)
               //fputs("Invalid option!\n\n", stdout);
               Invalid = 1;
          fputs(prompt, stdout);
          if (NULL == fgets(buffer, sizeof(buffer), stdin))
               return 1;
          errno = 0;
     } while ((1 != sscanf(buffer, "%d %n", i, &EndIndex)) || buffer[EndIndex] || errno);

     return 0;
}

/**
 * Difficult level menu handler
 */
void Input::inputDifficultLevel(FloodIt *game_)
{
     int difficultLevel = 0;

     // Display the game settings
     GUI::clearConsole();
     GUI::printSettings();

     // Handle the user input
     do
     {
          // Input data
          handleInput("Choose between 1 - 4: ", &difficultLevel);

          // Check the chosen level
          switch (difficultLevel)
          {
          // Easy
          case 1:
               // Set-up the game settings
               game_->restartGame(1, 25, 14);

               // Update the config file
               this->fileHandler->createConfigFile(this->filename.c_str(), game_->getGameSetting());

               // Go back to the main menu
               this->inputMainMenu(game_, true);
               break;
          /* Médio */
          case 2:
               // Set-up the game settings
               game_->restartGame(2, 35, 20);

               // Update the config file
               this->fileHandler->createConfigFile(this->filename.c_str(), game_->getGameSetting());

               // Go back to the main menu
               this->inputMainMenu(game_, true);
               break;
          /* Difícil */
          case 3:
               // Set-up the game settings
               game_->restartGame(3, 45, 25);

               // Update the config file
               this->fileHandler->createConfigFile(this->filename.c_str(), game_->getGameSetting());

               // Go back to the main menu
               this->inputMainMenu(game_, true);
          // Cancel the operation
          case 4:
               // Go back to the main menu
               this->inputMainMenu(game_, true);
          // Invalid option
          default:
               difficultLevel = 99;
               cout << "Invalid option!\n\n";
               break;
          }
     } while (difficultLevel == 99);
}

/**
 * Method to handle the main menu input
 */
void Input::inputMainMenu(FloodIt *game_, bool clearConsole_)
{
     int option = 0;

     do
     {
          // Print the main menu
          if (clearConsole_)
               GUI::clearConsole();
          else
               clearConsole_ = true;

          GUI::printMainMenu();

          // Input data
          handleInput("Choose between 1 - 4: ", &option);

          // Validate the input
          switch ((int)option)
          {
          // Invalid option
          case 0:
               option = 99;
               cout << "Invalid option!\n\n";
               break;
          // New game
          case 1:
               game_->restartGame(game_->getGameSetting()->difficultLevel,
                                  game_->getGameSetting()->maxNPlay,
                                  game_->getGameSetting()->boardSize); // Prepare the new game state
               GUI::clearConsole();                                    // Prepare the console
               GUI::printBoard(game_);                                 // Print the game board
               GUI::printPlayMenu();                                   // Display the play options
               option = this->gameInterface->play(game_);              // Handle the player game moves
               break;
          // Settings
          case 2:
               GUI::clearConsole();
               GUI::printSettings();
               this->inputDifficultLevel(game_);
               break;
          // Show credits
          case 3:
               GUI::clearConsole();
               GUI::printCredits();
               this->inputMainMenu(game_, false);
               break;
          // Exit game
          case 4:
               cout << "\nFinishing...\n\n";
               exit(EXIT_SUCCESS);
               break;
          // Invalid option
          default:
               option = 99;
               cout << "Invalid option!\n\n";
               break;
          }
     } while (option == 99);
}