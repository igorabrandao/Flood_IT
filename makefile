# ====================================================
# Makefile build 'Flood It project' using Make
# ====================================================
all:
	g++ -Wall -std=c++17 src/drive.cpp -I include/ -I lib/ -o bin/flood_it -g

val:
	valgrind ../bin/flood_it