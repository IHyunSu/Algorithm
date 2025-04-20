// Chained Matrix Multiplication

#include <iostream>
#include <vector>
#include <string>
#include <limits.h>


using namespace std;

typedef vector<vector<int> > matrix_t;

int minimum(int i, int j, int& mink, vector<int>& d, matrix_t& M) {
    int minValue = INT_MAX, value;
    for (int k = i; k <= j - 1; k++) {
        value = M[i][k] + M[k + 1][j] + d[i - 1] * d[k] * d[j];
        if (minValue > value) {
            minValue = value;
            mink = k;
        }
    }
    return minValue;
}

void minmult(int n, vector<int>& d, matrix_t& M, matrix_t& P) {
    for (int i = 1; i <= n; i++) {
        M[i][i] = 0;
    }

    for (int diagonal = 1; diagonal <= n - 1; diagonal++) {
        for (int i = 1; i <= n - diagonal; i++) {
            int j = i + diagonal;
            int k;
            M[i][j] = minimum(i, j, k, d, M);
            P[i][j] = k;
        }
    }
}

void order(int i, int j, matrix_t& P, string& s) {
    if (i == j) {
        s += "(A" + to_string(i) + ")";
    } else {
        int k = P[i][j];
        s += "(";
        order(i, k, P, s);
        order(k + 1, j, P, s);
        s += ")";
    }
}

int main() {
    // 행렬 크기 입력
    int n;
    cin >> n;

    // 행렬 크기에 맞는 차원 배열 입력
    vector<int> d(n + 1);
    for (int i = 0; i <= n; i++) {
        cin >> d[i];
    }

    matrix_t M(n + 1, vector<int>(n + 1, 0));  // 곱셈 결과 테이블
    matrix_t P(n + 1, vector<int>(n + 1, 0));  // 분할 지점 테이블

    // 행렬 곱셈 최소 비용 계산 시작
    minmult(n, d, M, P);

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (j == 1) {
                cout << M[i][j];
                if (i != n) cout << " ";
            }
            if (M[i][j] != 0) {
                cout << M[i][j];
                if (j != n) cout << " ";
            }
        }
        cout << endl;
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (j == 1) {
                cout << P[i][j];
                if (i != n) cout << " ";
            }
            if (P[i][j] != 0) {
                cout << P[i][j];
                if (j != n) cout << " ";
            }
        }
        cout << endl;
    }

    // 최적 곱셈 횟수 출력
    cout << M[1][n] << endl;

    // 최적 곱셈 순서 출력
    string optimal_order;
    order(1, n, P, optimal_order);
    cout << optimal_order << endl;

    return 0;
}
