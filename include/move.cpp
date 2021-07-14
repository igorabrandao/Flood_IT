#ifndef MOVE_HPP
#define MOVE_HPP

// ***************************************************
// ** Implements the functions related to Input
// ***************************************************
#include <iostream>
#include "FloodIt.h"
#include "GUI.cpp"
//#include "input.cpp"

using namespace std;

// ***************************************************
// ** Functions
// ***************************************************

namespace Move
{
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

          //Input::inputMatchMenu(game_);
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
          //Input::inputMatchMenu(game_);
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
               Move::handleLoser(game_);
               return 0;
          }
          else if (game_->isWinner() && game_->getRemainingTurns() >= 0)
          {
               // The player won the game :)
               Move::handleWinner(game_);
               return 1;
          } else {
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
                    //Input::inputMatchMenu(game_, userInput);
                    break;
               }
          } while (userInput == 'k');

          // Check if the user input is inside the valid range
          if ((uSelectedColor >= minRange) && (uSelectedColor < maxRange))
          {
               // Try to execute the player move
               game_->floodBoard(currentRow, currentCol, game_->getBoard()->getElemAt(currentRow, currentCol), uSelectedColor);

               // Increase the number of turns
               game_->setNumberOfMoves(game_->getNumberOfMoves() + 1);

               // Decrease the remaining turns
               game_->setRemainingTurns(game_->getRemainingTurns() - 1);

               // Check if the game ended and handle it accordling
               if (Move::handleGameEnd(game_) == -1)
               {
                    Move::play(game_);
               }
          }
     }
}

#endif