// ***************************************************
// ** Implements the functions from FloodIt class
// ***************************************************
#include "FloodIt.h"

// To use the assert() function
#include <cassert>

using std::bad_alloc;

// ***************************************************
// ** Functions
// ***************************************************

/**
 * Class constructor
 */
FloodIt::FloodIt(int boardSize_)
{
    // Set the initial attributes
    this->boardSize = boardSize_;
    this->nPlay = 0;

    try
    {
        // Allocate the memory for the board
        this->board = new Matrix<int>(boardSize_, boardSize_);
    }
    catch (const bad_alloc &exception)
    {
        // Here we need to take action
        cerr << "\n[main()]: Error during the Flood-it board allocation!\n";

        // Abort the program, used just in test case
        assert(false);
    }
}

/**
 * Class destructor
 * dot not need to be implemented since the Matrix data structure
 * already handled it :)
 */
FloodIt::~FloodIt() {}

/**
 * Function to generate random numbers
 */
int FloodIt::getRandomNumber() const
{
    int min = 0, max = 6;

    // Generate secret number between min and max
    return (rand() % max + min);
}

/**
 * Function to initialize the game
 */
void FloodIt::initGame() const
{
    int rows = this->board->rowSize();
    int cols = this->board->colSize();

    // Initialize random seed
    srand(time(NULL));

    // Fill the board with initial values
    for (auto i = 0; i < rows; i++)
    {
        for (auto j = 0; j < cols; j++)
        {
            this->board->add(i, j, this->getRandomNumber());
        }
    }
}

/**
 * Function to print the board
 */
void FloodIt::printBoard() const
{
    this->board->print();
}