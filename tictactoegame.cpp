#include <iostream>

using namespace std;

const int SIZE = 3;

void initializeBoard(char board[][SIZE]);
void displayBoard(const char board[][SIZE]);
bool checkWin(const char board[][SIZE], char player);
bool isBoardFull(const char board[][SIZE]);
void makeMove(char board[][SIZE], int row, int col, char player);


int main() {
    char board[SIZE][SIZE];
    char currentPlayer = 'X';

    initializeBoard(board);

    int row, col;
    bool gameWon = false;
    bool draw = false;

    while (!gameWon && !draw) {
        displayBoard(board);

        cout << "Player " << currentPlayer << ", enter your move (row and column): ";
        cin >> row >> col;

        makeMove(board, row, col, currentPlayer);

        if (checkWin(board, currentPlayer)) {
            gameWon = true;
            displayBoard(board);
            cout << "Player " << currentPlayer << " wins!" << endl;
        } else if (isBoardFull(board)) {
            draw = true;
            displayBoard(board);
            cout << "The game is a draw." << endl;
        } else {
            currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
        }
    }

    return 0;
}

// Function to initialize the Tic Tac Toe board
void initializeBoard(char board[][SIZE]) {
    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < SIZE; ++j) {
            board[i][j] = ' ';
        }
    }
}

// Function to display the Tic Tac Toe board
void displayBoard(const char board[][SIZE]) {
    cout << "-------------" << endl;
    for (int i = 0; i < SIZE; ++i) {
        cout << "| ";
        for (int j = 0; j < SIZE; ++j) {
            cout << board[i][j] << " | ";
        }
        cout << endl;
        cout << "-------------" << endl;
    }
}

// Function to check if a player has won
bool checkWin(const char board[][SIZE], char player) {
    // Check rows and columns
    for (int i = 0; i < SIZE; ++i) {
        if ((board[i][0] == player && board[i][1] == player && board[i][2] == player) ||
            (board[0][i] == player && board[1][i] == player && board[2][i] == player)) {
            return true;
        }
    }

    // Check diagonals
    if ((board[0][0] == player && board[1][1] == player && board[2][2] == player) ||
        (board[0][2] == player && board[1][1] == player && board[2][0] == player)) {
        return true;
    }

    return false;
}

// Function to check if the board is full
bool isBoardFull(const char board[][SIZE]) {
    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < SIZE; ++j) {
            if (board[i][j] == ' ') {
                return false;
            }
        }
    }
    return true;
}

// Function to make a move on the board
void makeMove(char board[][SIZE], int row, int col, char player) {
    if (row >= 0 && row < SIZE && col >= 0 && col < SIZE && board[row][col] == ' ') {
        board[row][col] = player;
    } else {
        cout << "Invalid move. Try again." << endl;
    }
}


