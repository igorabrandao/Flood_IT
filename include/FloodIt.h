/*!
	<PRE>
	SOURCE FILE : FloodIt.h
	DESCRIPTION.: FloodIt class - with implementation.
	AUTHOR......: Igor A. Brandão
	LOCATION....: NATAL/RN.
	SATARTED ON.: July/2021

	TO COMPILE..: Use makefile.
	OBS.........: Part of Flood-it Project.

	tail UPDATE.: July 12th, 2021.
	</pre>
*/
#ifndef FLOODIT_H
#define FLOODIT_H

#include <iostream>
#include "Matrix.h"
#include "boardColor.h"
#include "config.h"

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
    FloodIt(int boardSize_);       // Class constructor
    ~FloodIt();                    // Class destructor
    Matrix<int> *getBoard() const; // Function to return the entire board
    int getRandomNumber() const;   // Function to generate random numbers
    void initializeBoard() const;  // Function to initialize the game board
    void initGame() const;         // Function to initialize the game
};

#include "FloodIt.inl"
#endif