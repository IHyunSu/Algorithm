// Back Tracking : m-coloring problem

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
int n, m_edges;
int cnt = 0;
vector<int> vcolor;
vector<vector<int>> W;

// define algorithm functions
void m_coloring (int i, int m);
bool promising (int i);

// main function
int main ()
{
    cin >> n >> m_edges;
    vcolor.resize(n + 1);
    W.resize(n + 1, vector<int>(n + 1, 0));

    // 간선 정보 입력
    for (int i = 0; i < m_edges; i++)
    {
        int u, v;
        cin >> u >> v;
        W[u][v] = 1;
        W[v][u] = 1; // 무방향 그래프
    }

    int min_m = 1;

    // 가능한 최소 색 수를 찾을 때까지 증가
    while (true)
    {
        cnt = 0;
        fill(vcolor.begin(), vcolor.end(), 0);
        m_coloring (0, min_m);
        if (cnt > 0)
        {
            cout << min_m << '\n';
            cout << cnt << '\n';
            break;
        }
        min_m++;
    }

    return 0;
}

// define algorithm functions
void m_coloring (int i, int m)
{
    int color;
    if (promising(i))
    {
        if (i == n)
        {
            cnt++;
        }
        else
        {
            for (int color = 1; color <= m; color++)
            {
                vcolor[i + 1] = color;
                m_coloring(i + 1, m);
            }
        }
    }
}
bool promising (int i)
{
    int j;
    bool var_switch;

    var_switch = true;
    j = 1;
    while (j < i && var_switch)
    {
        if (W[i][j] && vcolor[i] == vcolor[j])
            var_switch = false;
        j++;
    }
    return var_switch;
}
