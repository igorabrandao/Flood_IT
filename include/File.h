/*!
	<PRE>
	SOURCE FILE : File.h
	DESCRIPTION.: File class - with implementation.
	AUTHOR......: Igor A. Brandão
	LOCATION....: NATAL/RN.
	SATARTED ON.: July/2021

	TO COMPILE..: Use makefile.
	OBS.........: Part of Flood-it Project.

	tail UPDATE.: July 14th, 2021.
	</pre>
*/
#ifndef FILE_H
#define FILE_H

#include <iostream>
#include <stdio.h>
#include "config.h"

using namespace std;

class File
{
private:
public:
    // ***************************************************
    // ** Functions
    // ***************************************************
    int checkConfigFile(const char *fname);
    void createConfigFile(const char *fname, CONFIG *config_);
};

#include "File.cpp"
#endif