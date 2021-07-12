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
    // Get the board dimensions
    int rows = this->board->rowSize();
    int cols = this->board->colSize();
    int boarSize = this->boardSize;

    // Variables to balance the values generation
    int currentValue, previousValue, valueFreq, maxRepetition = 3;
    int remainingColors[(int)BoardColor::Count] = {(boarSize / 6), (boarSize / 6), (boarSize / 6),
                                                   (boarSize / 6), (boarSize / 6), (boarSize / 6)};

    // Initialize random seed
    srand(time(NULL));

    // Fill the board with random initial values
    for (auto i = 0; i < rows; i++)
    {
        for (auto j = 0; j < cols; j++)
        {
            // Receive a random number
            currentValue = this->getRandomNumber();

            // Logic to balance the values
            if (remainingColors[currentValue] > 0 && valueFreq <= maxRepetition)
            {
                /**
                 * Scenario of a color under the max repetitions rule
                 */
                remainingColors[currentValue]--;

                // Add the element to the board
                this->board->add(i, j, currentValue);

                // Increase the repetition of the current color if it applies
                if (previousValue == currentValue)
                    valueFreq += 1;
            }
            else
            {
                /**
                 * Scenario of an unavailable color since it already was repeated
                 * more than allowed
                 */
                currentValue = this->getRandomNumber();

                // Add the element to the board
                this->board->add(i, j, currentValue);

                valueFreq = 0;
            }

            // Store the previous value
            previousValue = currentValue;
        }
    }
}

/**
 * Function to return the entire board
 */
Matrix<int> *FloodIt::getBoard() const
{
    return this->board;
}