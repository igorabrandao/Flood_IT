#ifndef INPUT_HPP
#define INPUT_HPP

// ***************************************************
// ** Implements the functions related to Input
// ***************************************************
#include <iostream>
#include "FloodIt.h"
#include "GUI.cpp"
#include "file.cpp"
#include "playInterface.cpp"

using namespace std;

// ***************************************************
// ** Functions
// ***************************************************

namespace Input
{
     string filename = "./config/config.txt";

     /**
      * Function to handle the user input
      */
     int handleInput(const char *prompt, int *i)
     {
          int Invalid = 0;
          int EndIndex;
          char buffer[100];

          do
          {
               if (Invalid)
                    fputs("Invalid option!\n\n", stdout);
               Invalid = 1;
               fputs(prompt, stdout);
               if (NULL == fgets(buffer, sizeof(buffer), stdin))
                    return 1;
               errno = 0;
          } while ((1 != sscanf(buffer, "%d %n", i, &EndIndex)) || buffer[EndIndex] || errno);

          return 0;
     }

     /**
      * Match menu handler
      */
     void inputMatchMenu(FloodIt *game_, char userInput_ = ' ')
     {
          char option = ' ';

          // Game input loop
          do
          {
               if (isblank(userInput_))
               {
                    // Input data
                    printf("Choose <n> <q> <s> <o> <v>: ");
                    scanf("%c", &option);
               }
               else
               {
                    option = userInput_;
               }

               // Check the inputted data
               switch (option)
               {
               // Invalid option
               case 0:
                    option = 99;
                    printf("Invalid option!\n\n");
                    break;
               // New game
               case 'n':
                    game_->restartGame();       // Prepare the new game state
                    GUI::clearConsole();        // Prepare the console
                    GUI::printBoard(game_);     // Print the game board
                    GUI::printPlayMenu();       // Display the play options
                    Playinterface::play(game_); // Handle the player game moves
                    break;
               // Quit game
               case 'q':
                    printf("\nFinishing...\n\n");
                    exit(EXIT_SUCCESS);
                    break;
               // Save game
               case 's':
                    Playinterface::saveGame(game_); // Save the current game
                    break;
               // Load previous game
               case 'o':
                    break;
               // Go back to main menu
               case 'v':
                    GUI::clearConsole();
                    GUI::printMainMenu();
                    Input::inputMainMenu(game_);
                    break;
               // Invalid option
               default:
                    option = 99;
                    printf("Invalid option!\n\n");
                    break;
               }
          } while (option == 99);

          // When the game interaction ends, go back to the main menu
          GUI::clearConsole();
          GUI::printMainMenu();
          Input::inputMainMenu(game_);
     }

     /**
      * Difficult level menu handler
      */
     void inputDifficultLevel(FloodIt *game_)
     {
          int difficultLevel = 0;

          // Display the game settings
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
                    game_->setGameSettings(1, 25, 14);

                    // Update the config file
                    File::createConfigFile(filename.c_str(), game_->getGameSetting());

                    /* Reinicia o jogo com as novas configurações*/
                    //inicializarJogo();
                    break;
               /* Médio */
               case 2:
                    // Set-up the game settings
                    game_->setGameSettings(2, 35, 20);

                    // Update the config file
                    File::createConfigFile(filename.c_str(), game_->getGameSetting());

                    /* Reinicia o jogo com as novas configurações*/
                    //inicializarJogo();
                    break;
               /* Difícil */
               case 3:
                    // Set-up the game settings
                    game_->setGameSettings(3, 45, 25);

                    // Update the config file
                    File::createConfigFile(filename.c_str(), game_->getGameSetting());

                    /* Reinicia o jogo com as novas configurações*/
                    //inicializarJogo();
               /* Cancelar */
               case 4:
                    /* Reinicia o jogo com as novas configurações*/
                    //inicializarJogo();
               /* Opção inválida */
               default:
                    difficultLevel = 99;
                    printf("Invalid option!\n\n");
                    break;
               }
          } while (difficultLevel == 99);
     }

     /**
      * Method to handle the main menu input
      */
     void inputMainMenu(FloodIt *game_)
     {
          int option = 0;

          do
          {
               // Input data
               handleInput("Choose between 1 - 4: ", &option);

               // Validate the input
               switch ((int)option)
               {
               // Invalid option
               case 0:
                    option = 99;
                    printf("Invalid option!\n\n");
                    break;
               // New game
               case 1:
                    Input::inputMatchMenu(game_, 'n'); // Call the game input passing the New Game as param
                    break;
               // Settings
               case 2:
                    GUI::clearConsole();
                    GUI::printSettings();
                    Input::inputDifficultLevel(game_);
                    break;
               // Show credits
               case 3:
                    GUI::clearConsole();
                    GUI::printCredits();
                    GUI::printMainMenu();
                    Input::inputMainMenu(game_);
                    break;
               // Exit game
               case 4:
                    printf("\nFinishing...\n\n");
                    exit(0);
                    break;
               // Invalid option
               default:
                    option = 99;
                    printf("Invalid option!\n\n");
                    break;
               }
          } while (option == 99);
     }
}

#endif