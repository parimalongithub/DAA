#include<iostream>
using namespace std;

const int N = 10; // Maximum board size (adjust as needed)

bool isSafe(int board[N][N], int row, int col, int n) {
    // Check the column on the left side
    for (int i = 0; i < row; i++){
        if (board[i][col]){
            return false;
        }
    }

    // Check upper left diagonal
    for (int i = row, j = col; i >= 0 && j >= 0; i--, j--)
        if (board[i][j]){
            return false;
        }

    // Check upper right diagonal
    for (int i = row, j = col; i >= 0 && j < n; i--, j++)
        if (board[i][j]){
            return false;
        }

    return true;
}

bool solveNQueensUtil(int board[N][N], int row, int n) {
    if (row == n) {
        // Print the board when all queens are placed
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++)
                cout << (board[i][j] ? "Q " : ". ");
            cout << endl;
        }
        cout << endl;
        return true;
    }

    bool res = false;
    for (int i = 0; i < n; i++) {
        if (isSafe(board, row, i, n)) {
            board[row][i] = 1;
            res = solveNQueensUtil(board, row + 1, n) || res;
            board[row][i] = 0; // Backtrack
        }
    }

    return res;
}

void solveNQueens(int n) {
    int board[N][N] = {0};
    if (!solveNQueensUtil(board, 0, n))
        cout << "No solution exists." << endl;
}

int main() {
    int n;
    cout << "Enter the size of the board (n): ";
    //cin >> n;
    solveNQueens(4);
    return 0;
}
