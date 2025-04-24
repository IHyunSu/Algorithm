// daijkstra algorithm
/* input case
5 8         <- size n, edge count k
1 2 7       <- vertex u, v and weight w
1 3 4
1 4 6
1 5 1
3 2 2
3 4 5
4 2 3
5 4 1
4           <- test case size n
2           <- vertex number t
3
4
5
*/

#include <iostream>
#include <vector>
#include <stack>
#define INF 0xffff
using namespace std;

typedef vector<vector<int>> matrix_t;
typedef vector<pair<int, int>> set_of_edges;
typedef pair<int, int> edge_t;

void daijkstra(int n, matrix_t &W, set_of_edges &F, vector<int> &touch, vector<int> &length);
void print_path(int t, const vector<int> &touch);
int main()
{
    int n, k;
    cin >> n >> k;

    matrix_t W(n + 1, vector<int>(n + 1, INF));
    for (int i = 1; i <= n; i++)
        W[i][i] = 0;

    for (int i = 0; i < k; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        W[u][v] = w;
    }

    set_of_edges F;
    vector<int> touch(n + 1), length(n + 1);
    daijkstra(n, W, F, touch, length);

    // F 집합 출력
    for (int i = 0; i < F.size(); i++)
    {
        int u = F[i].first;
        int v = F[i].second;
        cout << u << " " << v << " " << W[u][v] << endl;
    }

    int C;
    cin >> C;
    for (int i = 0; i < C; i++)
    {
        int t;
        cin >> t;
        print_path(t, touch);
    }

    return 0;
}

void daijkstra(int n, matrix_t &W, set_of_edges &F, vector<int> &touch, vector<int> &length)
{
    int vnear, min;
    F.clear();

    for (int i = 2; i <= n; i++)
    {
        touch[i] = 1;
        length[i] = W[1][i];
    }

    for (int j = 1; j < n; j++)
    {
        // 출력: length 테이블 상태
        for (int i = 2; i <= n; i++)
        {
            if (length[i] == -1)
                cout << touch[i]; // 이미 선택된 정점일 경우 이전 정점 출력
            else
                cout << touch[i];
            if (i != n)
                cout << " ";
        }
        cout << endl;

        min = INF;
        vnear = -1;
        for (int i = 2; i <= n; i++)
        {
            if (length[i] >= 0 && length[i] < min)
            {
                min = length[i];
                vnear = i;
            }
        }

        pair<int, int> edge;
        edge.first = touch[vnear];
        edge.second = vnear;
        F.push_back(edge);

        for (int i = 2; i <= n; i++)
        {
            if (length[i] > length[vnear] + W[vnear][i])
            {
                length[i] = length[vnear] + W[vnear][i];
                touch[i] = vnear;
            }
        }

        length[vnear] = -1;
    }

    for (int i = 2; i <= n; i++)
    {
        if (length[i] == -1)
            cout << touch[i]; // 이미 선택된 정점일 경우 이전 정점 출력
        else
            cout << touch[i];
        if (i != n)
            cout << " ";
    }
}

void print_path(int t, const vector<int> &touch)
{
    stack<int> path;
    int cur = t;
    while (cur != 1)
    {
        path.push(cur);
        cur = touch[cur];
    }
    path.push(1);
    while (!path.empty())
    {
        int top = path.top();
        cout << top;
        path.pop();
        if (!path.empty())
            cout << " ";
    }
    cout << endl;
}
 