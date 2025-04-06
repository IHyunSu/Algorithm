#include <iostream>
#include <vector>
using namespace std;
typedef vector<vector<int> > matrix_t;

void printMatrix(matrix_t board, int n);
int whereis(int n, int srow, int scol, int row, int col);
void fill(int n, matrix_t& board, int srow, int scol, int where);
void hole(int part, int where, int n, int srow, int scol, int row, int col);
void tromino(int n, matrix_t& board, int srow, int scol, int row, int col);

/*  
    ### Tromino-Puzzle 정복하기! ###
    n이 2가 될때까지 재귀된다.
    1/2사분면씩 4번 나눠지며 X 표시에 따라 각 사분면의 어디에서 색칠할지 정해진다.
    나눠질때마다 X 표시가 없는 중간쪽 3사분면들에 X 표시를 해야 하니까 n이 클 수록 실행횟수는 커지게 되는 것이다.
    ############################## 
*/

int hcol = 0, hrow = 0;
int cnt = 1;

int main () {
    int n, row, col;

    cin >> n >> row >> col;                     // 정방행렬의 사이즈와 없앨 칸 하나를 입력 받는다.
    matrix_t board(n+1, vector<int>(n+1, 0));   // board의 사이즈를 선언하고 0으로 초기화한다.
    int srow = 0, scol = 0;                     // 앞으로 나눌 부분들의 start-row와 start-col을 0으로 초기화한다.
    tromino(n, board, srow, scol, row, col);    // divide-and-conquer

    printMatrix(board, n);                      // 칠해진 board를 출력.
}

//
//  출력 부분
//

void printMatrix(matrix_t board, int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << board[i][j];
            if (j != n - 1) cout << " ";
        }
        cout << endl;
    }
}

//
//  X 표시가 4사분면 중 어느 W사분면에 속하는지 찾는 함수
//

int whereis(int n, int srow, int scol, int row, int col) {

    int m = n / 2;              //              n을 1/2 해서 중간 m을 가진다

    if (row - srow < m) {       //         행 조건 : X 가 있는 행 - 시작 행 < 중간
        if (col - scol < m) {   //         열 조건 : X 가 있는 열 - 시작 열 < 중간
            return 1;           //         ### 위 조건을 모두 만족하면 1사분면 ###
        } else {
            return 2;           //      ### 열 조건이 만족이 되지 않으면 2사분면 ###
        }
    } else {
        if (col - scol < m) {   // ### 행 조건이 만족되지 않고 열 조건이 만족되면 3사분면 ###
            return 3;
        } else {                //          ### 둘 다 만족되지 않으면 4사분면 ###
            return 4;
        }
    }

    return -1; // 없으면 오류니까 -1 반환
}

//
//  색칠하는 함수
//

void fill(int n, matrix_t& board, int srow, int scol, int where) {
    if (where != 1)
        board[srow][scol]   = cnt;
    if (where != 2)
        board[srow][scol+1] = cnt;
    if (where != 3)
        board[srow+1][scol] = cnt;
    if (where != 4)
        board[srow+1][scol+1] = cnt;
    
    cnt++;
}

//
//  구멍 X를 판단하고 색칠해야 하는 중간 값을 찾아주는 함수
//

void hole(int part, int where, int n, int srow, int scol, int row, int col) {
    int m = n / 2;
    if (part != where) {
        row = srow + m - 1;
        col = scol + m - 1;
        if (part == 2 || part == 4)
            col += 1;
        if (part == 3 || part == 4)
            row += 1;
    }
    hrow = row, hcol = col;
}

/*
    재귀 조건 : 중간 값 n이 2가 되면 색칠하고 종료

            0 X 표시 된 W사분면 where 값 얻기
            1 n이 2가 아니라면 중간 나눈 값 m 얻기
            2 where값이 아닌 사분면의 중간쪽을 색칠하기
            3 각 사분면마다 구멍을 찾고 구멍을 기준으로, 중간값인 hrow와 hcol값을 받기
            4 hrow, hcol값으로 재귀하기
            5 2, 3, 4사분면도 마찬가지로 hole로 hrow, hcol 찾고 재귀 반복
*/

void tromino(int n, matrix_t& board, int srow, int scol, int row, int col) {
    int where = whereis(n, srow, scol, row, col);
    if (n == 2) {
        fill(n, board, srow, scol, where);
    } else {
        int m = n / 2;                                     //   fill(<정방행렬 사이즈>, <행렬>, <중간값 T>, <중간값 Y>, <X 표시 사분면>)
        fill(n, board, srow + m - 1, scol + m - 1, where); //   정방행렬의 사이즈 n과, 중간 값 T와 Y와, X표시가 어디 되어있는지 넘겨준다.
        hole(1, where, n, srow, scol, row, col);           
        tromino(m, board, srow, scol, hrow, hcol);
        hole(2, where, n, srow, scol, row, col);
        tromino(m, board, srow, scol+m, hrow, hcol);
        hole(3, where, n, srow, scol, row, col);
        tromino(m, board, srow+m, scol, hrow, hcol);
        hole(4, where, n, srow, scol, row, col);
        tromino(m, board, srow+m, scol+m, hrow, hcol);
    }
}
