#ifndef GUI_HPP
#define GUI_HPP

// ***************************************************
// ** Implements the functions related to GUI
// ***************************************************
#include <iostream>
#include <cassert>

#include "color.hpp"
#include "boardColor.h"
#include "Matrix.h"

using namespace std;

// ***************************************************
// ** Functions
// ***************************************************

namespace GUI
{
    /**
     * Function to print the board
     */
    void printBoard(Matrix<int> *board)
    {
        // Get the board attributes
        int rows = board->rowSize();
        int cols = board->colSize();

        // Print definitions
        string textBackground, textColor, vDisplay = "";

        //imprimirCabecalho();

        // Loop over the board
        for (auto i = 0; i < rows; i++)
        {
            for (auto j = 0; j < cols; j++)
            {
                switch (board->getElemAt(i, j))
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
                vDisplay = " " + std::to_string(board->getElemAt(i, j));

                // Display the coloured tile
                cout << color::rize(vDisplay, textColor, textBackground);
            }
            cout << endl;
        }
        //imprimirRodape();
    }
}

#endif