/*!
	<PRE>
	SOURCE FILE : GameInterface.h
	DESCRIPTION.: GameInterface class - with implementation.
	AUTHOR......: Igor A. Brandão
	LOCATION....: NATAL/RN.
	SATARTED ON.: July/2021

	TO COMPILE..: Use makefile.
	OBS.........: Part of Flood-it Project.

	tail UPDATE.: July 14th, 2021.
	</pre>
*/
#ifndef GAME_INTERFACE_H
#define GAME_INTERFACE_H

#include <iostream>
#include <thread> // std::this_thread::sleep_for
#include <chrono> // std::chrono::seconds
#include "GUI.cpp"
//#include "Input.h"

using namespace std;

class GameInterface
{
private:
public:
    // ***************************************************
    // ** Attributes
    // ***************************************************
    Input *inputHandler;

    // ***************************************************
    // ** Functions
    // ***************************************************
    void play(FloodIt *game_);
    void handleWinner(FloodIt *game_);
    void handleLoser(FloodIt *game_);
    int handleGameEnd(FloodIt *game_);
    void saveGame(FloodIt *game_);
    void loadGame(FloodIt *game_);
};

#include "GameInterface.cpp"
#endif