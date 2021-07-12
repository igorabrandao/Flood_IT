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

/**
 * Enum with available color options
 */
enum COLOR
{
    BLUE = 0,
    RED = 1,
    GREEN = 2,
    YELLOW = 3,
    PINK = 4,
    PURPLE = 5
};

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
};

#include "FloodIt.inl"
#endif