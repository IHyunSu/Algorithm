#include <iostream>
#include <vector>
using namespace std;

#define INF 0xffff

typedef vector<vector<int> > matrix_t;

matrix_t his_nearest;
matrix_t his_dist;

void prim(int n, matrix_t& W);

int main() {
    int n, k;
    cin >> n >> k;

    matrix_t W(n + 1, vector<int>(n + 1, INF));
    his_nearest.assign(n+1, vector<int>(n+1));
    his_dist.assign(n+1, vector<int>(3));

    for (int i = 1; i <= n; i++) W[i][i] = 0;

    for (int i = 0; i < k; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        W[u][v] = w;
        W[v][u] = w;
    }

    prim(n, W);

    for (int i = 1; i <= n; i++) {
        for (int j = 2; j <= n; j++) {
            cout << his_nearest[i][j];
            if (j != n) cout << " ";
        }
        cout << endl;
    }

    for (int i = 1; i <= n - 1; i++) {
        for (int j = 0; j < 3; j++) {
            cout << his_dist[i][j];
            if (j != 2) cout << " ";
        }
        cout << endl;
    }

    return 0;
}

void prim(int n, matrix_t& W) {
    vector<int> nearest(n + 1);
    vector<int> distance(n + 1);

    // 초기 설정
    for (int i = 2; i <= n; i++) {
        nearest[i] = 1;
        distance[i] = W[1][i];
    }


    for (int i = 1; i <= n - 1; i++) {
        int min = INF;
        int vnear = -1;

        for (int j = 2; j <= n; j++) {
            if (distance[j] >= 0 && distance[j] < min) {
                min = distance[j];
                vnear = j;
            }
        }

        for (int j = 2; j <= n; j++) {
            his_nearest[i][j] = nearest[j];
        }

        his_dist[i][0] = vnear;
        his_dist[i][1] = nearest[vnear];
        his_dist[i][2] = distance[vnear];

        distance[vnear] = -1;

        // 거리 및 nearest 갱신
        for (int j = 2; j <= n; j++) {
            if (W[vnear][j] < distance[j]) {
                distance[j] = W[vnear][j];
                nearest[j] = vnear;
            }
        }
    }

    // 마지막 nearest 상태를 한 번 더 저장
    for (int j = 2; j <= n; j++) {
        his_nearest[n][j] = nearest[j];
    }
}
