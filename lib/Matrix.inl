// ***************************************************
// ** Implements the functions from Matrix class
// ***************************************************
#include "Matrix.h"

// To use the assert() function
#include <cassert>

using std::bad_alloc;

// ***************************************************
// ** Functions
// ***************************************************

/**
 * Class constructor
 */
template <typename T>
Matrix<T>::Matrix(int rows_, int cols_)
{
	// Define the Matrix initial attributes
	this->rows = rows_;
	this->cols = cols_;

	try
	{
		// Update the Matrix size
		this->mSize = (rows_ * cols_);

		// Allocate the necessary memory the matrix rows
		this->matrix = new Array<T>(mSize);
	}
	catch (const bad_alloc &exception)
	{
		// Here we need to take action
		cerr << "\n[main()]: Error during the Matrix[] allocation!\n";

		// Abort the program, used just in test case
		assert(false);
	}
}

/**
 * Class destructor
 */
template <typename T>
Matrix<T>::~Matrix()
{
	// Deallocate the memory of the current matrix
	delete[] matrix;
}

/**
 * Copy constructor (deep copy)
 */
template <typename T>
Matrix<T>::Matrix(const Matrix &obj_)
{
	// Get the original Matrix total size
	int nSize = obj_.size();

	try
	{
		// Allocate the necessary memory to the new Matrix
		this->matrix = new Array<T>[nSize];

		for (int i = 0; i < nSize; i++)
		{
			// Copy each element from the origin Matrix
			this->matrix[i] = obj_.matrix[i];
		}
	}
	catch (const bad_alloc &exception)
	{
		// Here we need to take action
		cerr << "\n[main()]: Error during the Matrix[] allocation in copy constructor!\n";

		// Abort the program, used just in test case
		assert(false);
	}
}

/**
 * Function to get the index of the Matrix element
 */
template <typename T>
int Matrix<T>::getIndex(int row_, int col_) const
{
	/**
	 * The 1d matrix version uses the following
	 * formula to index an element:
	 * (i * nCol + j), where i and j are the current loop indexes
	 */
	return row_ * this->cols + col_;
}

/**
 * Function to return the matrix rows size
 */
template <typename T>
int Matrix<T>::rowSize() const
{
	return this->rows;
}

/**
 * Function to return the matrix columns size
 */
template <typename T>
int Matrix<T>::colSize() const
{
	return this->cols;
}

/**
 * Function to return the matrix total size
 */
template <typename T>
int Matrix<T>::size() const
{
	return this->rowSize() * this->colSize();
}

/**
 * Function to add an element into the Matrix
 */
template <typename T>
void Matrix<T>::add(int row_, int col_, const T &obj_)
{
	// Check the matrix boundaries
	if (row_ < 0 || row_ >= this->rows)
		throw std::out_of_range("<< Row out of range exception! >>");
	else if (col_ < 0 || col_ >= this->cols)
		throw std::out_of_range("<< Col out of range exception! >>");
	else {
		// Add the new element
		this->matrix->add(obj_);
	}
}

/**
 * Function to get an element by its position
 */
template <typename T>
T &Matrix<T>::getElemAt(int row_, int col_) const
{
	if (row_ < 0 || row_ >= this->rows)
		throw std::out_of_range("<< Row out of range exception! >>");
	else if (col_ < 0 || col_ >= this->cols)
		throw std::out_of_range("<< Col out of range exception! >>");

	return this->matrix->getAt(this->getIndex(row_, col_));
}

/*template <typename T>
void Matrix<T>::expand(int newSize_)
{
	int szToExpand = newSize_;

	// If the new size wasn't informed, just double the Matrix
	if (szToExpand == 0)
		szToExpand *= 2;

	try
	{
		// Create a temp Matrix and allocate the necessary memory to it
		T *temp = new T[szToExpand];

		for (auto i = 0; i < this->nrOfEl; i++)
		{
			// Copy each element from the origin Matrix
			temp[i] = T(this->arr[i]);
		}

		// Delete the original Matrix
		delete[] this->arr;

		// Copy the temp Matrix to the original
		this->arr = temp;

		// Update the number of elements
		this->nrOfEl = szToExpand;
	}
	catch (const bad_alloc &exception)
	{
		// Here we need to take action
		cerr << "\n[main()]: Error during the Matrix[] allocation!\n";

		// Abort the program, used just in test case
		assert(false);
	}
}*/

/**
 * Function to print the Matrix
 */
template <typename T>
void Matrix<T>::print(string MatrixName_) const
{
	if (MatrixName_.compare("") != 0)
		cout << MatrixName_ << ": " << endl << "[" << endl;
	else
		cout << "[ " << endl;

	// Print the new int Matrix values
	for (int i = 0; i < this->rows; i++)
	{
		for (int j = 0; j < this->cols; j++)
		{
			cout << this->getElemAt(i, j) << " ";
		}

		// Break the line
		cout << endl;
	}

	cout << "]" << endl;
}

// ***************************************************
// ** Overload operators
// ***************************************************

/**
 * Overload of the operator=
 * 
 * Implemented to support the following:
 * 
 * Matrix1 = Matrix2 = Matrix3; cascading assignment
 * Matrix1 = Matrix1; self-assignment
 * (Matrix1 = Matrix2) = Matrix3; odd but valid
 */
/*template <typename T>
Matrix<T> &Matrix<T>::operator=(const Matrix &rhs)
{
	// Verify if it's a self-assignment
	if (this != &rhs)
	{
		// Free the memory of the current Matrix
		delete[] arr;

		// Perform the deep copy of the rhs
		int size = rhs.size();

		try
		{
			// Allocate the necessary memory to the Matrix
			this->arr = new T[size];

			for (int i = 0; i < size; i++)
			{
				// Copy each element from the origin Matrix
				this->arr[i] = rhs.arr[i];
			}

			// Update the number of elements
			this->nrOfEl = size;
		}
		catch (const bad_alloc &exception)
		{
			// Here we need to take action
			cerr << "\n[main()]: Error during the Matrix[] allocation!\n";

			// Abort the program, used just in test case
			assert(false);
		}
	}

	// Return a reference for Matrix for cascading assignment
	return (*this);
}*/

/**
 * Overload of the operator[]
 */
template <typename T>
T &Matrix<T>::operator[](int index_)
{
	if (index_ < 0 || index_ >= this->rows)
		throw std::out_of_range("<< Row out of range exception! >>");

	return this->matrix->getAt(index_);
}

template <typename T>
const T &Matrix<T>::operator[](int index_) const
{
	if (index_ < 0 || index_ >= this->rows)
		throw std::out_of_range("<< Row out of range exception! >>");

	return this->matrix->getAt(index_);
}