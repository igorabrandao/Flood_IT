/*!
	<PRE>
	SOURCE FILE : FloodIt.h
	DESCRIPTION.: FloodIt class - with implementation.
	AUTHOR......: Igor A. Brandão
	LOCATION....: NATAL/RN.
	SATARTED ON.: July/2021

	TO COMPILE..: Use makefile.
	OBS.........: Part of Data Structures Project.

	tail UPDATE.: July 12th, 2021.
	</pre>
*/
#ifndef FLOODIT_H
#define FLOODIT_H

#include <iostream>
#include "Matrix.h"

using namespace std;

class FloodIt
{
private:
    // ***************************************************
    // ** Attributes
    // ***************************************************
    int boardSize;      // Board size
    int nPlay;          // Number of played turns
    Matrix<int> *board; // The FloodIt board itself

public:
    // ***************************************************
    // ** Functions
    // ***************************************************
    FloodIt(int boardSize_);     // Class constructor
    ~FloodIt();                  // Class destructor
    int getRandomNumber() const; // Function to generate random numbers
    void initGame() const;       // Function to initialize the game
    void printBoard() const;     // Function to print the board
};

#include "FloodIt.inl"
#endif