#ifndef GUI_HPP
#define GUI_HPP

// ***************************************************
// ** Implements the functions related to GUI
// ***************************************************
#include <iostream>
#include "FloodIt.h"
#include "color.hpp"
#include "boardColor.h"

using namespace std;

// ***************************************************
// ** Functions
// ***************************************************

namespace GUI
{
     /**
     * Method to print the header
     */
     void printHeader()
     {
          cout << "FLOOD IT!" << endl;
          cout << "=========" << endl
               << endl;
          cout << "============================================" << endl;
     }

     /**
     * Method to print the footer
     */
     void printFooter()
     {
          cout << "============================================" << endl
               << endl;
     }

     /**
     * Method to print the board
     */
     void printBoard(FloodIt *game_)
     {
          // Get the board attributes
          int rows = game_->getBoard()->rowSize();
          int cols = game_->getBoard()->colSize();

          // Print definitions
          string textBackground, textColor, vDisplay = "";

          // Print the header
          printHeader();

          // Loop over the board
          for (auto i = 0; i < rows; i++)
          {
               for (auto j = 0; j < cols; j++)
               {
                    switch (game_->getBoard()->getElemAt(i, j))
                    {
                    case 0:
                         textBackground = textColor = "Blue";
                         break;
                    case 1:
                         textBackground = textColor = "Red";
                         break;
                    case 2:
                         textBackground = textColor = "Green";
                         break;
                    case 3:
                         textBackground = textColor = "Yellow";
                         break;
                    case 4:
                         textBackground = textColor = "Light Magenta";
                         break;
                    case 5:
                         textBackground = textColor = "Cyan";
                         break;
                    }

                    // Prepare the value to display
                    vDisplay = " " + std::to_string(game_->getBoard()->getElemAt(i, j));

                    // Display the coloured tile
                    cout << color::rize(vDisplay, textColor, textBackground);
               }
               cout << endl;
          }

          // Print the footer
          printFooter();
     }

     /**
     * Method to generate the main menu
     */
     void printMainMenu()
     {
          printHeader();
          cout << "Choose a game option:" << endl
               << endl;
          cout << "1) New game" << endl;
          cout << "2) Settings" << endl;
          cout << "3) Credits" << endl;
          cout << "4) Exit" << endl;
          printFooter();
     }

     /**
     * Method to generate the play menu
     */
     void printPlayMenu()
     {
          // Possible options
          cout << endl
               << "PLAY OPTIONS:" << endl;
          cout << "====================" << endl;

          cout << color::rize(" 0 ", "White", "Blue");
          cout << color::rize(" 1 ", "White", "Red");
          cout << color::rize(" 2 ", "White", "Green");
          cout << color::rize(" 3 ", "Dark Gray", "Yellow");
          cout << color::rize(" 4 ", "White", "Light Magenta");
          cout << color::rize(" 5 ", "White", "Cyan");
          cout << endl
               << endl;
     }

     /**
     * Method to generate the game options
     */
     void printGameOptions()
     {
          cout << endl
               << "GAME OPTIONS:" << endl;
          cout << "====================" << endl;
          cout << "n: Start game" << endl
               << endl;
          cout << "q: Quit game" << endl
               << endl;
          cout << "s: Save game" << endl
               << endl;
          cout << "o: Load saved game" << endl
               << endl;
          cout << "v: Go to main menu" << endl
               << endl;
     }

     /**
     * Method to generate the game credits
     */
     void printCredits()
     {
          cout << endl
               << "//**********************************************************************";
          cout << endl
               << "//**********  IGOR A. BRANDAO ©";
          cout << endl
               << "//**********";
          cout << endl
               << "//**********  PGM: FLOOD IT";
          cout << endl
               << "//**********";
          cout << endl
               << "//**********  LOCATION: NATAL/RN";
          cout << endl
               << "//**********";
          cout << endl
               << "//**********  VERSION:	1.0";
          cout << endl
               << "//**********";
          cout << endl
               << "//**********  July/2021 - Creation";
          cout << endl
               << "//**********";
          cout << endl
               << "//**********************************************************************" << endl
               << endl;
     }

     /**
      * Method to print the game settings
      */
     void printSettings()
     {
          cout << endl
               << "===>CHOOSE THE GAME LEVEL<===";
          cout << endl
               << "==> 1 - EASY -> 14x14 Board";
          cout << endl
               << "==> 2 - MODERATE -> 20x20 Board";
          cout << endl
               << "==> 3 - HARD -> 25x25 Board";
          cout << endl
               << "==> 4 - Cancel" << endl;
          cout << endl
               << "======================================" << endl
               << endl;
     }

#ifdef _WIN32
#include <windows.h>

     void clearConsole()
     {
          system("cls");
     }

#else
#include <unistd.h>

     void clearConsole()
     {
          system("clear");
     }

#endif
}

#endif