/** \file Source.cpp
 *  \brief     A little program
 *  \details   The program source to show the menu of options
 *  \author    Minh Nguyen Truong Quang Minh
 *  \version   0.1
 *  \date      26/05/2024
 *  \pre       First initialize the system.
 *  \bug       No bugs so far
 *  \copyright University of Nicosia.
 */

#include <iostream>
#include "Matrix.h"

using namespace std;

// Fun prototypes
void showMenu();

/**
 * The <code>main</code> is the driver function that kick-starts the
 * application.
 * <BR>
 * @return Returns <code>0</code> on success, any other value otherwise.
 */
int main() {
    int choice = 0;

    // Defining the matrix
    const int MAX_ROW = 5;
    double mat[MAX_ROW][MAX_COL];
    double* sumRows;
    double* sumCols;

    do {
        showMenu();
        cin >> choice;

        switch (choice)
        {
        case 1:
            fillWithRandomNum(mat, MAX_ROW);
            break;
        case 2:
            int row;
            cout << "\nEnter the row you want to sum: ";
            cin >> row;

            cout << "\nSum of row is: " << sumOfRow(mat, row, MAX_ROW);
            break;
        case 3:
            int collumn;
            cout << "\nEnter the collumn you want to sum: ";
            cin >> collumn;

            cout << "\nSum of collumn is: " << sumOfCol(mat, collumn, MAX_ROW);
            break;
        case 4:
            printMatrix(mat, MAX_ROW);
            break;
        case 5:
            if (!makeIdentityMatrix(mat, MAX_ROW))
                cerr << "\nNot a square matrix, cannot apply function";
            break;
        case 6:
            if (isIdentityMatrix(mat, MAX_ROW))
                cout << "\nMatrix is an identity matrix";
            else
                cout << "\nMatrix is NOT an identity matrix";
            break;
        case 7:
            cout << "\nSum of diagonal is: " << sumOfDiagonal(mat, MAX_ROW);
            break;
        case 8:
            sumRows = sumOfRows(mat, MAX_ROW);

            for (int i = 0; i < MAX_ROW; ++i)
                cout << "\nSum of row " << i << ": " << sumRows[i];

            delete[] sumRows;
            break;
        case 9:
            sumCols = sumOfCols(mat, MAX_ROW);

            for (int i = 0; i < MAX_ROW; ++i)
                cout << "\nSum of cols " << i << ": " << sumCols[i];

            delete[] sumCols;
            break;
        case 0:
            break;
        default:
            cerr << "\nWrong choice";
        }
    } while (choice != 0);

    cout << "\nHave a nice day:)";
    return 0;
}

/**
 * The <code>showMenu</code> function displays the menu options to the user.
 */
void showMenu() {
    cout << "\n1) Fill Matrix with random numbers";
    cout << "\n2) Sum of a specific row";
    cout << "\n3) Sum of a specific column";
    cout << "\n4) Show matrix";
    cout << "\n5) Make Identity Matrix";
    cout << "\n6) Test if Identity Matrix";
    cout << "\n7) Sum of Diagonal";
    cout << "\n8) Sum of all rows";
    cout << "\n9) Sum of all cols";
    cout << "\n0) Exit";
    cout << "\nEnter choice: ";
}
