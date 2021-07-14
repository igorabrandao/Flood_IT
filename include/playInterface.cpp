#ifndef PLAY_INTERFACE_HPP
#define PLAY_INTERFACE_HPP

// ***************************************************
// ** Implements the functions related to Input
// ***************************************************
#include <iostream>
#include <thread> // std::this_thread::sleep_for
#include <chrono> // std::chrono::seconds
#include "FloodIt.h"
#include "GUI.cpp"

using namespace std;

// ***************************************************
// ** Functions
// ***************************************************

namespace Playinterface
{
     /**
      * Match menu handler
      */
     int handleMatchMenu(FloodIt *game_, char *userInput_)
     {
          // Game input loop
          do
          {
               if (isblank(userInput_[0]))
               {
                    // Input data
                    printf("Choose <n> <q> <s> <o> <v>: ");
                    scanf("%c", userInput_);
               }

               // Check the inputted data
               switch (*userInput_)
               {
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
                    break;
               // Invalid option
               default:
                    userInput_[0] = 'k';
                    printf("Invalid option!\n\n");
                    break;
               }
          } while (*userInput_ == 'k');

          return EXIT_SUCCESS;
     }

     /**
      * Function to handle when the player wins
      */
     void handleWinner(FloodIt *game_)
     {
          GUI::clearConsole();
          GUI::printBoard(game_);
          printf("\n\n***CONGRATULATION, YOU WIN!!!***\n\n\n");
          GUI::printGameOptions();

          // Restart the game
          game_->restartGame();

          Playinterface::handleMatchMenu(game_, nullptr);
     }

     /**
      * Function to handle when the player loses
      */
     void handleLoser(FloodIt *game_)
     {
          GUI::clearConsole();
          GUI::printBoard(game_);
          printf("\n\n***YOU LOSE, TRY AGAIN!***\n\n\n");
          GUI::printGameOptions();
          Playinterface::handleMatchMenu(game_, nullptr);
     }

     /**
      * Function to handle the game end
      */
     int handleGameEnd(FloodIt *game_)
     {
          /**
           * Checks if the player has reached the maximum number of moves and 
           * has not flooded the board
           */
          if (!game_->isWinner() && !game_->getRemainingTurns())
          {
               // The player lost the game :(
               Playinterface::handleLoser(game_);
               return 0;
          }
          else if (game_->isWinner() && game_->getRemainingTurns() >= 0)
          {
               // The player won the game :)
               Playinterface::handleWinner(game_);
               return 1;
          }
          else
          {
               // The players neither won or lost the game yet
               return -1;
          }
     }

     /**
      * Function to manage the user movements
      */
     void play(FloodIt *game_)
     {
          char userInput = ' ';
          int uSelectedColor = -1;
          int currentRow = 0, currentCol = 0;

          // Define the play range
          int minRange = 0;
          int maxRange = (int)BoardColor::Count - 1;

          // Recreate the updated board
          GUI::clearConsole();
          GUI::printBoard(game_);
          GUI::printGameOptions();
          GUI::printPlayMenu();

          // Print the current game stats
          cout << "\nNumber of turns: " << game_->getNumberOfMoves();
          cout << "\nRemaining turns: " << game_->getRemainingTurns();
          /* *************************************** */

          // Process the user input
          do
          {
               // Choose the color
               printf("\n\nChoose a color (%i - %i): ", minRange, maxRange);
               scanf(" %c", &userInput);

               // Handle the user input as ascII
               switch (userInput)
               {
               case '0':
                    uSelectedColor = 0;
                    break;
               case '1':
                    uSelectedColor = 1;
                    break;
               case '2':
                    uSelectedColor = 2;
                    break;
               case '3':
                    uSelectedColor = 3;
                    break;
               case '4':
                    uSelectedColor = 4;
                    break;
               case '5':
                    uSelectedColor = 5;
                    break;
               default:
                    Playinterface::handleMatchMenu(game_, &userInput);
                    break;
               }
          } while (userInput == 'k');

          // Check if the user input is inside the valid range
          if ((uSelectedColor >= minRange) && (uSelectedColor <= maxRange))
          {
               // Try to execute the player Playinterface
               game_->floodBoard(currentRow, currentCol, game_->getBoard()->getElemAt(currentRow, currentCol), uSelectedColor);

               // Increase the number of turns
               game_->setNumberOfMoves(game_->getNumberOfMoves() + 1);

               // Decrease the remaining turns
               game_->setRemainingTurns(game_->getRemainingTurns() - 1);

               // Check if the game ended and handle it accordling
               if (Playinterface::handleGameEnd(game_) == -1)
               {
                    Playinterface::play(game_);
               }
          }
     }

     /**
      * Function to save the current game
      */
     void saveGame(FloodIt *game_)
     {
          //salvarPartida(tabuleiro_, config_);
          printf("\n\n***GAME SAVED SUCCESSFULLY!***\n\n");
          std::this_thread::sleep_for(std::chrono::seconds(2));
          //jogar(tabuleiro_, config_, numJogadas_);
     }

     /**
      * Function to load a saved game
      */
     void loadGame(FloodIt *game_)
     {
          /*numJogadas_ = carregarPartida(tabuleiro_, config_, &tamanho_);

          // Verifica o tamanho da matriz
          if (tamanho_ == config_->tam_tabuleiro)
          {
               printf("\n\n***JOGO CARREGADO COM SUCESSO!***\n\n");
               std::this_thread::sleep_for (std::chrono::seconds(2));
               jogar(tabuleiro_, config_, numJogadas_);
               break;
          }
          else
          {
               GUI::clearConsole();
               printf("\nSua Matriz Salva eh diferente da atual!\n");
               printf("Configure sua matriz para o tamanho %ix%i\n", tamanho_, tamanho_);
               std::this_thread::sleep_for (std::chrono::seconds(3));

               GUI::clearConsole();
               GUI::printMainMenu();
               inputMainMenu(game_);
               break;
          }*/
     }
}

#endif