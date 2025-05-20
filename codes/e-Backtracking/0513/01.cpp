// Back Tracking : n-queens problem

/**
 * 개요: DFS 알고리즘 지식, Tree를 Backtracking하는 방법, Promising 알고리즘 지식이 필요하다.
 * 같은 행(row)에는 퀸을 놓지 않는다.
 * 같은 열(column)이나 같은 대각선(diagonal)에 놓이는 지를 확인
 * 1. 같은 열 체크 
 *  => (col[i] - i번째 행에서 퀸이 놓여있는 열의 위치, col[k] - k번째 행에서 퀸이 놓여있는 열의 위치)
 *      - col[i] == col[k] : 유망하지 않다.
 * 2. 대각선 체크
 *  => 왼쪽에서 위협하는 퀸에 대해서
 *      - col[i] - col[k] == i - k
 *  => 오른쪽에서 위협하는 퀸에 대해서
 *      - col[i] - col[k] == k - i
 */

// includes
#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// define global variable
int cnt = 0;
string last_solution;

// define algorithm functions
void n_queens (int i, vector<int> col);
bool promising(int i, vector<int> col);

// main functions
int main () 
{
    int N;
    cin >> N;
    vector<int> col(N+1, 0);
    n_queens(0, col);
    cout << cnt << '\n';
    for (int i = 0; i < last_solution.size(); i++)
    {
        if (last_solution != " ");
            cout << last_solution[i];
    }
    cout << '\n';

    return 0;
}

// realization algorithm functions
void n_queens (int i, vector<int> col)
{
    int n = col.size() - 1;
    if (promising(i, col))
    {
        if (i == n)
        {
            cnt++;
            string current_solution;
            for (int i = 1; i <= n; i++) {
                current_solution += to_string(col[i]);
            }
            if (current_solution > last_solution) {
                last_solution = current_solution;
            }
        }
        else
        {
            for (int j = 1; j < n + 1; j++)
            {
                col[i + 1] = j;
                n_queens(i + 1, col);
            }
        }
    }
}

bool promising(int i, vector<int> col)
{
    int k = 1;
    bool flag = true;
    while (k < i && flag == true) 
    {
        if (col[i] == col[k] || abs(col[i] - col[k]) == (i - k))
            flag = false;
        k++;
    }
    return flag;
}