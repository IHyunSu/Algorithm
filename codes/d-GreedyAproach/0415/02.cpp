// MST: Kruskal's Algorithm
/* input case
5 7         <- size n, edge count k
1 2 1       <- vertex u,v and weight w
1 3 3
2 3 7
2 4 6
3 4 4
3 5 2
4 5 5
*/

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include <queue> // priority_queue를 위한 헤더
using namespace std;

typedef struct edge {
    int u, v, w;
} edge_t;

struct edge_compare {
    bool operator()(edge_t e1, edge_t e2) {
        return e1.w > e2.w; // 최소 힙
    }
};

typedef vector<edge_t> set_of_edges;
typedef priority_queue<edge_t, vector<edge_t>, edge_compare> PriorityQueue;

vector<int> dset;

void kruskal(int n, int m, set_of_edges& E, set_of_edges& F);
void dset_init(int n);
int dset_find(int i);
void dset_merge(int p, int q);

int main () {
    int n, k; // 정점 수 n, 간선 수 k
    cin >> n >> k;

    set_of_edges E;
    for (int i = 0; i < k; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        E.push_back({u, v, w});
    }

    set_of_edges F; // MST에 포함될 간선들

    kruskal(n, k, E, F);

    for (edge_t e : F) {
        cout << e.u << " " << e.v << " " << e.w << '\n';
    }

    return 0;
}

void kruskal(int n, int m, set_of_edges& E, set_of_edges& F) {
    int p, q;
    edge_t e;
    PriorityQueue PQ;

    // 모든 간선을 우선순위 큐에 삽입
    for (edge_t edge : E)
        PQ.push(edge);

    dset_init(n);
    int count = 0;

    while (!PQ.empty() && count < n - 1) {
        e = PQ.top(); PQ.pop();

        p = dset_find(e.u);
        q = dset_find(e.v);

        if (p != q) {
            dset_merge(p, q);
            F.push_back(e);
            count++;
        }
    }
}

void dset_init(int n) {
    dset.resize(n + 1); // 1-based 인덱싱
    for (int i = 1; i <= n; i++)
        dset[i] = i;
}

int dset_find(int i) {
    if (dset[i] == i)
        return i;
    return dset[i] = dset_find(dset[i]); // 경로 압축
}

void dset_merge(int p, int q) {
    int root_p = dset_find(p);
    int root_q = dset_find(q);
    if (root_p != root_q)
        dset[root_q] = root_p;
}

