#include <iostream>
#include <vector>
using namespace std;

#define N 8

bool isSafe(int x, int y, vector<vector<int>>& board) {
    return (x >= 0 && x < N && y >= 0 && y < N && board[x][y] == -1);
}

void printSolution(const vector<vector<int>>& board) {
    for (int x = 0; x < N; x++) {
        for (int y = 0; y < N; y++)
            cout << " " << board[x][y] << " ";
        cout << endl;
    }
}

bool solveKTUtil(int x, int y, int movei, vector<vector<int>>& board) {
    if (movei == N * N)
        return true;

    // List of all possible moves for a knight
    // 1st move
    if (isSafe(x + 2, y + 1, board)) {
        board[x + 2][y + 1] = movei;
        if (solveKTUtil(x + 2, y + 1, movei + 1, board))
            return true;
        else
            board[x + 2][y + 1] = -1; // backtracking
    }

    // 2nd move
    if (isSafe(x + 2, y - 1, board)) {
        board[x + 2][y - 1] = movei;
        if (solveKTUtil(x + 2, y - 1, movei + 1, board))
            return true;
        else
            board[x + 2][y - 1] = -1; // backtracking
    }

    // 3rd move
    if (isSafe(x - 2, y + 1, board)) {
        board[x - 2][y + 1] = movei;
        if (solveKTUtil(x - 2, y + 1, movei + 1, board))
            return true;
        else
            board[x - 2][y + 1] = -1; // backtracking
    }

    // 4th move
    if (isSafe(x - 2, y - 1, board)) {
        board[x - 2][y - 1] = movei;
        if (solveKTUtil(x - 2, y - 1, movei + 1, board))
            return true;
        else
            board[x - 2][y - 1] = -1; // backtracking
    }

    // 5th move
    if (isSafe(x + 1, y + 2, board)) {
        board[x + 1][y + 2] = movei;
        if (solveKTUtil(x + 1, y + 2, movei + 1, board))
            return true;
        else
            board[x + 1][y + 2] = -1; // backtracking
    }

    // 6th move
    if (isSafe(x + 1, y - 2, board)) {
        board[x + 1][y - 2] = movei;
        if (solveKTUtil(x + 1, y - 2, movei + 1, board))
            return true;
        else
            board[x + 1][y - 2] = -1; // backtracking
    }

    // 7th move
    if (isSafe(x - 1, y + 2, board)) {
        board[x - 1][y + 2] = movei;
        if (solveKTUtil(x - 1, y + 2, movei + 1, board))
            return true;
        else
            board[x - 1][y + 2] = -1; // backtracking
    }

    // 8th move
    if (isSafe(x - 1, y - 2, board)) {
        board[x - 1][y - 2] = movei;
        if (solveKTUtil(x - 1, y - 2, movei + 1, board))
            return true;
        else
            board[x - 1][y - 2] = -1; // backtracking
    }

    return false;
}

bool solveKT() {
    vector<vector<int>> board(N, vector<int>(N, -1));

    // Starting from the first block
    board[0][0] = 0;

    if (!solveKTUtil(0, 0, 1, board)) {
        cout << "Solution does not exist";
        return false;
    } else {
        printSolution(board);
        return true;
    }
}

int main() {
    solveKT();
    return 0;
}


