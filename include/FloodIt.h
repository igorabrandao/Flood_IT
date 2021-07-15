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
    int boardSize;       // Board size
    int nPlay;           // Number of played turns
    int remainingTurns;  // Number of remaining turns
    Matrix<int> *board;  // The FloodIt board itself
    CONFIG gameSettings; // Struct with the game settings

    // ***************************************************
    // ** Functions
    // ***************************************************
    int getRandomNumber() const;         // Function to generate random numbers
    void initializeBoard() const;        // Function to initialize the game board
    void setGameSettings(int, int, int); // Function to set-up the game settings

public:
    // ***************************************************
    // ** Getter & setter
    // ***************************************************
    int getNumberOfMoves() { return nPlay; };
    void setNumberOfMoves(int moves_) { nPlay = moves_; };

    int getRemainingTurns() { return remainingTurns; };
    void setRemainingTurns(int value_) { remainingTurns = value_; };

    int getBoardSize() { return boardSize; };

    // ***************************************************
    // ** Functions
    // ***************************************************
    FloodIt(int boardSize_);             // Class constructor
    ~FloodIt();                          // Class destructor
    Matrix<int> *getBoard() const;       // Function to return the entire board
    CONFIG *getGameSetting();            // Function to return the game settings
    void restartGame(int, int, int);     // Function to restart the game
    void floodBoard(int, int, int, int); // Function to implement the flood mechanics
    int isWinner();                      // Function to check if the player won the game
};

#include "FloodIt.inl"
#endif