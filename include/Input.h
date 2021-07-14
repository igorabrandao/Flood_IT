/*!
	<PRE>
	SOURCE FILE : Input.h
	DESCRIPTION.: Input class - with implementation.
	AUTHOR......: Igor A. Brandão
	LOCATION....: NATAL/RN.
	SATARTED ON.: July/2021

	TO COMPILE..: Use makefile.
	OBS.........: Part of Flood-it Project.

	tail UPDATE.: July 14th, 2021.
	</pre>
*/
#ifndef INPUT_H
#define INPUT_H

#include <iostream>
#include "FloodIt.h"
#include "GUI.cpp"
#include "GameInterface.h"
#include "File.h"

using namespace std;

class Input
{
private:
public:
    // ***************************************************
    // ** Attributes
    // ***************************************************
    File *fileHandler;
    GameInterface *gameInterface;
    string filename = "./config/config.txt";

    // ***************************************************
    // ** Functions
    // ***************************************************
    int handleInput(const char *prompt, int *i);
    void inputDifficultLevel(FloodIt *game_);
    void inputMatchMenu(FloodIt *game_, char *);
    void inputMainMenu(FloodIt *game_);
};

#include "Input.cpp"
#endif