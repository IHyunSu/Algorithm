// Back Tracking : Hamiltonian Circuit

/**
 * 
 */

// include
#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// define constant
int n, m, cnt = 0;
vector<int> vindex;
vector<vector<int>> W;

// define algorithm functions
void hamiltonian (int i);
bool promising (int i);

// main function
int main ()
{
    cin >> n >> m;
    W.resize(n + 1, vector<int>(n + 1, 0));
    vindex.resize(n);

    // 인접 행렬 입력
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        W[u][v] = 1;
        W[v][u] = 1;
    }

    // 시작 정점 고정: vindex[0] = 1
    vindex[0] = 1;

    // 해밀턴 회로 탐색
    hamiltonian(0);

    // 결과 출력
    cout << cnt << '\n';

    return 0;
}

// realization algorithm
void hamiltonian (int i) 
{
    int j;

    if (promising(i))
    {
        if (i == n - 1)
        {
            // 마지막 정점에서 시작점으로 돌아갈 수 있는 경우만 회로 성립
            if (W[vindex[i]][vindex[0]])
                cnt++;
        }
        else
        {
            for (int j = 2; j <= n; j++)
            {
                vindex[i + 1] = j;
                hamiltonian(i + 1);
            }
        }
    }
}

bool promising (int i)
{
    int j;
    bool flag;

    // 유망성 판단 조건
    if (i > 0 && !W[vindex[i - 1]][vindex[i]])
        flag = false;
    else
    {
        flag = true;
        j = 1;
        while (j < i && flag)
        {
            if (vindex[i] == vindex[j]) // 중복 방문 체크
                flag = false;
            j++;
        }
    }
    return flag;
}
