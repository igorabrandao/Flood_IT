/*!
	<PRE>
	SOURCE FILE : Matrix.h
	DESCRIPTION.: Matrix class - with implementation.
	AUTHOR......: Igor A. Brandão
	LOCATION....: NATAL/RN.
	SATARTED ON.: July/2021

	TO COMPILE..: Use makefile.
	OBS.........: Part of Data Structures Project.

	tail UPDATE.: July 12th, 2021.
	</pre>
*/
#ifndef MATRIX_H
#define MATRIX_H

#include <iostream>
#include <string>
#include "Array.h"

using namespace std;

/**
 * Matrix template class
 */
template <class T>
class Matrix
{
private:
    // ***************************************************
    // ** Attributes
    // ***************************************************
    int rows;         // Number of rows
    int cols;         // Number of cols
    int mSize;        // Matrix size
    Array<T> *matrix; // The matrix based on the Array class

public:
    // ***************************************************
    // ** Functions
    // ***************************************************
    Matrix(int rows_ = 0, int cols_ = 0);        // Class constructor
    ~Matrix();                                   // Class Destructor
    Matrix(const Matrix &obj_);                  // Copy constructor
    int getIndex(int row_, int col_) const;      // Function to get the index of the Matrix position
    int rowSize() const;                         // Function to return the matrix rows size
    int colSize() const;                         // Function to return the matrix columns size
    int size() const;                            // Function to return the matrix total size
    void add(int row_, int col_, const T &obj_); // Function to add an element into the matrix
    T &getElemAt(int row_, int col_) const;      // Function to get an element by its position
    void expand(int newSize_ = 0);               // Function to expand the matrix N positions
    void print(string matrixName_ = "") const;   // Function to print the matrix

    // ***************************************************
    // ** Overload operators
    // ***************************************************
    Matrix &operator=(const Matrix &rhs);
    T &operator[](int index_);
    const T &operator[](int index_) const;
};

#include "Matrix.inl"
#endif

/* --------------------- [ End of the Matrix.h header ] ------------------- */
/* ========================================================================= */