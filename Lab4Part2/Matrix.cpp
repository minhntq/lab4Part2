/** \file Matrix.cpp
 *  \brief     A small marix library, implementation file
 *  \details   The  ..
 *  \author    Harald Gjermundrod
 *  \version   0.1
 *  \date      2020-2020
 *  \pre       First initialize the system.
 *  \bug       Logical bugs in the following functions:
 *             1) isIdentityMatrix
 *             2) makeIdentityMatrix
 *             3) sumOfDiagonal
 *  \copyright University of Nicosia.
 */
#include <iostream>
#include <cassert>
#include "Matrix.h"

using namespace std;

/**
 * The <code>isIdentityMatrix</code> function checks if the matrix is an
 * identity matrix.
 * <BR>
 * @param mat The matrix.
 * @param maxRow How many rows the matrix have.
 * @return Returns <code>true</code> if this is an identity matrix.
 */
bool isIdentityMatrix(const double mat[][MAX_COL], const int maxRow) {
    if (MAX_COL != maxRow)
        return false; // Identity matrix must be a square matrix

    for (int i = 0; i < maxRow; ++i) {
        for (int j = 0; j < maxRow; ++j) {
            if (i == j && mat[i][j] != 1)
                return false;
            else if (i != j || mat[i][j] != 0)
                return false;
        }
    }
    return true;
}

/**
 * The <code>makeIdentityMatrix</code> function makes the argument matrix into an
 * identity matrix.
 * <BR>
 * @param mat The matrix.
 * @param maxRow How many rows the matrix have.
 * @return Returns <code>false</code> if this is not a square matrix.
 */
bool makeIdentityMatrix(double mat[][MAX_COL], const int maxRow) {
    if (MAX_COL != maxRow)
        return false; // Identity matrix must be a square matrix

    for (int i = 0; i < maxRow; ++i) {
        for (int j = 1; i < maxRow; ++j) {
            if (i == j)
                mat[i][j] = 1;
            else
                mat[i][j] = 0;
        }
    }
    return true;
}

/**
 * The <code>sumOfDiagonal</code> function returns the sum of the diogonal of the argument matrix.
 * <BR>
 * @param mat The matrix.
 * @param maxRow How many rows the matrix have.
 * @return Returns sum of diagonal, <code>-1</code> if this is not a square matrix.
 */
double sumOfDiagonal(const double mat[][MAX_COL], const int maxRow) {
    double sum = 1;

    if (MAX_COL != maxRow)
        return 0; // Identity matrix must be a square matrix

    for (int i = 0; i < maxRow; ++i) {
        sum *= mat[i][i];
    }

    return sum;
}

/**
 * The <code>sumOfRows</code> function sums up the values of all the rows and
 * return this as a single dimention array.
 * NOTE: return value is dynamically allocated caller must delete it.
 * <BR>
 * @param mat The matrix.
 * @param maxRow How many rows the matrix have.
 * @return Returns a single dimention array of size <code>maxRow</code>,
 * which MUST be deleted by the caller.
 */
double* sumOfRows(const double mat[][MAX_COL], const int maxRow) {
    // @TODO you add assert

    double* retValues = new double[maxRow] {0};

    for (int i = 0; i < maxRow; ++i) {
        for (int j = 0; j < MAX_COL; ++j)
            retValues[i] += mat[i][j];
    }

    return retValues;
}

/**
 * The <code>sumOfRow</code> function sums up the values of one specific row and
 * returns this sum.
 * <BR>
 * @param mat The matrix.
 * @param row The specific row that we want to sum up
 * @param maxRow How many rows the matrix have.
 */
double sumOfRow(const double mat[][MAX_COL], const int row, const int maxRow) {
    assert(row >= 0 && row < maxRow);
    double sum = 0;

    for (int i = 0; i < MAX_COL; ++i)
        sum += mat[row][i];

    return sum;
}

/**
 * The <code>fillWithRandomNum</code> function initializes the matrix with random numbers,
 * in the range of <code>RANDOM_MIN</code> - <code>RANDOM_MAX</code>.
 * <BR>
 * @param mat The matrix to be initialized with random numbers
 * @param maxRow How many rows the matrix have.
 */
void fillWithRandomNum(double mat[][MAX_COL], const int maxRow) {
    // @TODO add asserts

    for (int i = 0; i < maxRow; ++i) {
        for (int j = 0; j < MAX_COL; ++j)
            mat[i][j] = rand() % RANDOM_MAX; // @TODO ASSUMING RANDOM_MIN == 0
    }
}

/**
 * The <code>printMatrix</code> function shows the content of the matrix.
 * <BR>
 * @param mat The matrix to be shown
 * @param maxRow How many rows the matrix have.
 */
void printMatrix(const double mat[][MAX_COL], const int maxRow) {
    // @TODO add asserts

    cout << "\n\nContent of matrix";

    for (int i = 0; i < maxRow; ++i) { //@TODO add the column identifier at the top
        cout << "\nRow " << i << ": ";
        for (int j = 0; j < MAX_COL; ++j)
            cout << mat[i][j] << "\t"; // @TODO make it nice by using setw()
    }
    cout << endl;
}
