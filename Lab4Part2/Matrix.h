/** \file Matrix.h
 *  \brief     A small marix library, header file
 *  \details   The  ..
 *  \author    Minh Nguyen Truong Quang
 *  \version   0.1
 *  \date      24/05/2024
 *  \pre       First initialize the system.
 *  \bug       No bugs so far
 *  \copyright University of Nicosia.
 */
#ifndef MATRIX_H
#define MATRIX_H

 // Global constant
const int MAX_COL = 5;
const int RANDOM_MIN = 0;
const int RANDOM_MAX = 50;

double* sumOfRows(const double mat[][MAX_COL], const int maxRow);
double* sumOfCols(const double mat[][MAX_COL], const int maxRow);
double sumOfRow(const double mat[][MAX_COL], const int row, const int maxRow);
double sumOfCol(const double mat[][MAX_COL], const int column, const int maxRow);
void fillWithRandomNum(double mat[][MAX_COL], const int maxRow);
void printMatrix(const double mat[][MAX_COL], const int maxRow);

bool isIdentityMatrix(const double mat[][MAX_COL], const int maxRow);
bool makeIdentityMatrix(double mat[][MAX_COL], const int maxRow);
double sumOfDiagonal(const double mat[][MAX_COL], const int maxRow);

double* sumOfRows(const double mat[][MAX_COL], const int maxRow);

#endif // 
