#include <iostream>
#include <vector>
using namespace std;

typedef vector<vector<int> > Matrix;

const int INF = 999;

void floyd2(int n, Matrix& W, Matrix& D, Matrix& P) {
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (i == j) D[i][j] = 0;
            else if (W[i][j] == 0) D[i][j] = INF;
            else D[i][j] = W[i][j];

            P[i][j] = 0;
        }
    }

    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (D[i][k] != INF && D[k][j] != INF && D[i][j] > D[i][k] + D[k][j]) {
                    D[i][j] = D[i][k] + D[k][j];
                    P[i][j] = k;
                }
            }
        }
    }
}

void path(Matrix& P, int u, int v, vector<int>& p) {
    int k = P[u][v];
    if (k != 0) {
        path(P, u, k, p);
        p.push_back(k);
        path(P, k, v, p);
    }
}

int main () {
    int N, M, u, v, w;
    cin >> N >> M;

    Matrix W(N+1, vector<int>(N+1, 0));
    
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            if (i != j) W[i][j] = INF;
        }
    }

    for (int i = 0; i < M; i++) {
        cin >> u >> v >> w;
        W[u][v] = w;
    }

    Matrix D(N+1, vector<int>(N+1, INF));
    Matrix P(N+1, vector<int>(N+1, 0));

    floyd2(N, W, D, P);

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            if (D[i][j] == INF) cout << INF;
            else cout << D[i][j];
            if (j != N) cout << " ";
        }
        cout << endl;
    }

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            if (P[i][j] == INF) cout << INF;
            else cout << P[i][j];
            if (j != N) cout << " ";
        }
        cout << endl;
    }

    int K, start, end;
    cin >> K;
    
    for (int i = 0; i < K; i++) {
        cin >> start >> end;
        vector<int> p;
        path(P, start, end, p);

        if (D[start][end] == INF) {
            cout << "NONE" << endl;
            continue;
        }
        
        cout << start << " ";
        for (int node : p) {
            cout << node << " ";
        }
        cout << end << endl;
        
    }   
    
    return 0;
}