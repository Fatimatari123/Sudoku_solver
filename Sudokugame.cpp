#include <iostream>
using namespace std;

bool findEmpty(int grid[9][9], int& row, int& col) {//finding empty cell
    for (row = 0; row < 9; row++) {
        for (col = 0; col < 9; col++) {
            if (grid[row][col] == 0)
                return true;
        }
    }
    return false;
}

void pri(int grid[9][9]) {//for printing grid

    cout << "\n\n+-------+-------+-------+" << endl;
    for (int i = 0; i < 9; i++) {
        if (i == 3 || i == 6) {
            cout << "+-------+-------+-------+" << endl;
        }
        cout << "| ";
        for (int j = 0; j < 9; j++) {
            if (grid[i][j] == 0)
                cout << "  ";
            else
                cout << grid[i][j] << " ";
            if (j == 2 || j == 5 || j == 8) {
                cout << "| ";
            }
        }
        cout << endl;
    }
    cout << "+-------+-------+-------+" << endl;
}

bool valid(int grid[9][9], int row, int col, int num) {//to check validity
    for (int i = 0; i < 9; i++) {
        if (grid[row][i] == num || grid[i][col] == num)
            return false;
    }
    int startRow = row - row % 3, startCol = col - col % 3;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (grid[startRow + i][startCol + j] == num)
                return false;
        }
    }
    return true;
}

bool solver(int grid[9][9]) {//sudoku solverusing backtracking
    int row, col;
    if (!findEmpty(grid, row, col))
        return true;

    for (int num = 1; num <= 9; num++) {
        if (valid(grid, row, col, num)) {
            grid[row][col] = num;
            if (solver(grid))
                return true;
            grid[row][col] = 0; // Backtracking
        }
    }
    return false;
}

int main() {
    int grid[9][9] = {
    {5,3,0, 0,7,0, 0,0,0},
    {6,0,0, 1,9,5, 0,0,0},
    {0,9,8, 0,0,0, 0,6,0},

    {8,0,0, 0,6,0, 0,0,3},
    {4,0,0, 8,0,3, 0,0,1},
    {7,0,0, 0,2,0, 0,0,6},

    {0,6,0, 0,0,0, 2,8,0},
    {0,0,0, 4,1,9, 0,0,5},
    {0,0,0, 0,8,0, 0,7,9}
    };



    cout << "\tWELCOME TO SUDOKU GAME\n";
    cout << "\n\nThe Sudoku Grid is: \n";
    pri(grid);

    if (solver(grid)) {
        cout << "\nThe puzzle is solved\n" << endl;
        pri(grid);
    }
    else {
        cout << "\nNo solution exists\n";
    }
    return 0;
}
