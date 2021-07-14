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

    try
    {
        // Allocate the memory for the board
        this->board = new Matrix<int>(boardSize_, boardSize_);

        // Initialize the game board
        this->initializeBoard();

        // Define the default game settings
        this->setGameSettings(1, 25, 14);
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
 * Function to return the entire board
 */
Matrix<int> *FloodIt::getBoard() const
{
    return this->board;
}

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
 * Function to initialize the game board
 */
void FloodIt::initializeBoard() const
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
 * Function to set-up the game settings
 */
void FloodIt::setGameSettings(int level_, int nPlay_, int boardSize_)
{
    // Set the basic game definitions
    this->gameSettings.difficultLevel = level_; // Difficult level
    this->gameSettings.maxNPlay = nPlay_;       // Max number of turns
    this->gameSettings.boardSize = boardSize_;  // The game board size

    this->nPlay = 0;                                                    // The current number of turns
    this->remainingTurns = (this->gameSettings.maxNPlay - this->nPlay); // The remaining turns
}

/**
 * Function to return the game settings
 */
CONFIG *FloodIt::getGameSetting()
{
    return &this->gameSettings;
}

/**
 * Function to load a previous game
 */
void FloodIt::loadGame(FloodIt previousGame_)
{
    // TODO
}

/**
 * Function to manage the current game
 */
void FloodIt::play()
{
    char userInput = ' ';
    int uSelectedColor = -1;
    int currentRow, currentCol = 0;

    // Define the play range
    int minRange = 0;
    int maxRange = (int)BoardColor::Count - 1;

    // Recreate the updated board
    GUI::clearConsole();
    GUI::printBoard(*this);
    GUI::printGameOptions();
    GUI::printPlayMenu();

    // Print the current game stats
    cout << "\nNumber of turns: " << this->nPlay;
    cout << "\nRemaining turns: " << this->remainingTurns;
    /* *************************************** */

    // Process the user input
    do
    {
        // Choose the color
        cout << "\n\nChoose a color (0 - 5): ";
        scanf(" %c", &userInput);

        // Handle the user input as ascII
        switch (userInput)
        {
        case '0':
            uSelectedColor = 0;
            break;
        case '1':
            uSelectedColor = 1;
            break;
        case '2':
            uSelectedColor = 2;
            break;
        case '3':
            uSelectedColor = 3;
            break;
        case '4':
            uSelectedColor = 4;
            break;
        case '5':
            uSelectedColor = 5;
            break;
        default:
            Input::inputMatchMenu(*this, userInput);
            break;
        }
    } while (userInput == 'k');

    // Check if the user input is inside the valid range
    if ((uSelectedColor >= minRange) && (uSelectedColor < maxRange))
    {
        // Try to execute the player move
        this->floodBoard(currentRow, currentCol, this->getBoard()->getElemAt(currentRow, currentCol), uSelectedColor);

        // Increase the number of turns
        this->nPlay++;

        // Decrease the remaining turns
        this->remainingTurns--;

        /**
         * Checks if the player has reached the maximum number of moves and 
         * has not flooded the board
         */
        if (!this->isWinner() && !this->remainingTurns)
        {
            // The player lost the game :(
            GUI::clearConsole();
            GUI::printBoard(*this);
            printf("\n\n***YOU LOSE, TRY AGAIN!***\n\n\n");
            GUI::printGameOptions();
            Input::inputMatchMenu(*this);
        }
        else if (this->isWinner() && this->remainingTurns >= 0)
        {
            // The player won the game :)
            GUI::clearConsole();
            GUI::printBoard(*this);
            printf("\n\n***CONGRATULATION, YOU WIN!!!***\n\n\n");
            GUI::printGameOptions();

            // Restart the game
            this->initializeBoard();
            this->setGameSettings(this->getGameSetting()->difficultLevel,
                                  this->getGameSetting()->maxNPlay,
                                  this->getGameSetting()->boardSize);

            Input::inputMatchMenu(*this);
        }
        else
        {
            // Update the game
            this->play();
        }
    }
}

/**
 * Function to traverse the board and implement the flood mechanics
 */
void FloodIt::floodBoard(int row_, int col_, int previousColor_, int newColor_)
{
    // Check if the previous move is different from the current one
    if (previousColor_ != newColor_)
    {
        // Check the edge case (0,0) == previousColor
        if (this->getBoard()->getElemAt(row_, col_) == previousColor_)
        {
            /* --- HANDLE ALL CASES --- */

            // The current row and col position is updated to the color entered by the user.
            this->getBoard()->getElemAt(row_, col_) = newColor_;

            /*
             * tests if the row is not the last, if true and row+1, (bottom row), 
             * is equal to the old color calls the function recursively with
             * row+1 and col as parameters.
             */
            if (row_ < this->boardSize - 1 && this->getBoard()->getElemAt(row_ + 1, col_) == previousColor_)
                floodBoard(row_ + 1, col_, previousColor_, newColor_);

            /*
             * tests if the col is not the last, if true and col +1 (right col) is equal to the old color,
             * calls the function recursively passing the value of row and col+1 as parameters.
             */
            if (col_ < this->boardSize - 1 && this->getBoard()->getElemAt(row_, col_ + 1) == previousColor_)
                floodBoard(row_, col_ + 1, previousColor_, newColor_);

            /*
             * tests if the row is not the first, if true and if the cell of row-1, (top row), is equal to the old color,
             * calls the function recursively assigning row_-1 and col_ as parameters.
             */
            if (row_ > 0 && this->getBoard()->getElemAt(row_ - 1, col_) == previousColor_)
                floodBoard(row_ - 1, col_, previousColor_, newColor_);

            /*
             * tests if the col is not the first, if true and if col_-1, (left col), is equal to the old color,
             * calls the function recursively assigning row_ and col_- 1 as parameters.
             */
            if (col_ > 0 && this->getBoard()->getElemAt(row_, col_ - 1) == previousColor_)
                floodBoard(row_, col_ - 1, previousColor_, newColor_);
        }
    }
}

/**
 * Function to check if the player won the game
 */
int FloodIt::isWinner()
{
    // Initial parameters
    int winnerStatus = 0;
    int refColor = this->getBoard()->getElemAt(0, 0);

    // Get the board dimensions
    int boardRows = this->getBoard()->rowSize();
    int boardCols = this->getBoard()->colSize();

    // Check if the entire board has just one color
    for (auto i = 0; i < boardRows; i++)
    {
        for (auto j = 0; j < boardCols; j++)
        {
            if (this->getBoard()->getElemAt(i, j) == refColor)
                winnerStatus = 1;
            else
                return 0;
        }
    }
    return winnerStatus;
}