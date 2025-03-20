#include <iostream>
#include <vector>
using namespace std;
typedef vector<vector<int> > matrix_t;

void printMatrix(matrix_t board, int n);
int whereis(int& n, int srow, int scol, int row, int col);
void fill(int& n, matrix_t& board, int srow, int scol, int where);
void hole(int part, int where, int& n, int srow, int scol, int& row, int& col);
void tromino(int& n, matrix_t& board, int srow, int scol, int row, int col);

int main () {
    int n, row, col;

    cin >> n >> row >> col;

    matrix_t board(n+1, vector<int>(n+1));

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            board[i][j] = 0;

    
    int srow = 0, scol = 0;

    tromino(n, board, srow, scol, row, col);

    printMatrix(board, n);
}

void printMatrix(matrix_t board, int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << board[i][j];
            if (j != n) cout << " ";
        }
        cout << endl;
    }
}

int whereis(int& n, int srow, int scol, int row, int col) {
    int m = n / 2;
    if (row - srow < m) {
        if (col - scol < m) {
            return 1;
        } else {
            return 2;
        }
    } else {
        if (col - scol < m) {
            return 3;
        } else {
            return 4;
        }
    }
    return -1;
}

void fill(int& n, matrix_t& board, int srow, int scol, int where) {
    if (where != 1)
        board[srow][scol]   = n;
    if (where != 2)
        board[srow][scol+1] = n;
    if (where != 3)
        board[srow+1][scol] = n;
    if (where != 4)
        board[srow+1][scol+1] = n;
}

void hole(int part, int where, int& n, int srow, int scol, int& row, int& col) {
    int m = n / 2;
    if (part != where) {
        row = srow + m - 1;
        col = scol + m - 1;
        if (part == 2 || part == 4)
            col += 1;
        if (part == 3 || part == 4)
            row += 1;
    }
}

void tromino(int& n, matrix_t& board, int srow, int scol, int row, int col) {
    int where = whereis(n, srow, scol, row, col);
    if (n == 2) {
        fill(n, board, srow, scol, where);
    } else {
        int m = n / 2;
        fill(n, board, srow + m - 1, scol + m - 1, where);
        int hrow, hcol;
        hole(1, where, n, srow, scol, hrow, hcol);
        tromino(m, board, srow, scol, hrow, hcol);
        hole(2, where, n, srow, scol, row, col);
        tromino(m, board, srow, scol+m, hrow, hcol);
        hole(3, where, n, srow, scol, hrow, hcol);
        tromino(m, board, srow+m, scol, hrow, hcol);
        hole(4, where, n, srow, scol, row, col);
        tromino(m, board, srow+m, scol+m, hrow, hcol);
    }
}
