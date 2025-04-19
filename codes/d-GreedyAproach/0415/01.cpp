#include <iostream>
#include <vector>
#include <tuple>
using namespace std;

#define INF 0xffff

typedef vector<vector<int> > matrix_t;
typedef vector<tuple<int, int, int> > set_of_edges;
typedef pair<int, int> edge_t;

void prim(int n, matrix_t& W, set_of_edges& F);

int main() {
    int n, k; // 정점 수, 간선 수
    cin >> n >> k;

    matrix_t W(n + 1, vector<int>(n + 1, INF));

    for (int i = 0; i < k; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        W[u][v] = w;
        W[v][u] = w; // 무방향 그래프
    }

    set_of_edges F;
    prim(n, W, F);

    for (int i = 0; i < F.size(); i++) {
        cout << get<0>(F[i]) << " " << get<1>(F[i]) << " " << get<2>(F[i]) << endl;
    }

    return 0;
}

void prim(int n, matrix_t& W, set_of_edges& F) {
    int vnear, min;
    vector<int> nearest(n + 1);
    vector<int> distance(n + 1);

    F.clear();

    for (int i = 2; i <= n; i++) {
        nearest[i] = 1;
        distance[i] = W[1][i];
    }

    for (int i = 1; i <= n - 1; i++) {
        min = INF;
        for (int j = 2; j <= n; j++) {
            if (distance[j] >= 0 && distance[j] < min) {
                min = distance[j];
                vnear = j;
            }
        }

        F.push_back(make_tuple(vnear, nearest[vnear], distance[vnear]));
        distance[vnear] = -1;

        for (int j = 2; j <= n; j++) {
            if (W[vnear][j] < distance[j]) {
                distance[j] = W[vnear][j];
                nearest[j] = vnear;
            }
        }
    }
}
