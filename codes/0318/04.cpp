#include <iostream>
#include <vector>

using namespace std;
typedef vector<vector<int> > matrix_t;

matrix_t input(int N);
matrix_t square(matrix_t a, int N, int K);
matrix_t unitMatrix(int N);
void print(matrix_t S, int N);

int main () {
    int N, K;
    cin >> N >> K;
    matrix_t a(N + 1, vector<int>(N + 1));
    a = input(N);
    matrix_t r(N + 1, vector<int>(N + 1));

    r = square(a, N, K);

    print(r, N);
}

matrix_t input(int N) {
    matrix_t tmp(N + 1, vector<int>(N + 1));
    for (int i = 1; i < N + 1; i++)
        for (int j = 1; j < N + 1; j++)
            cin >> tmp[i][j];

    return tmp;
}

matrix_t square(matrix_t a, int N, int K) {
    matrix_t res = unitMatrix(N);

    for (int index = 0; index < K; index++) {
        matrix_t temp(N + 1, vector<int>(N + 1));
        for (int i = 1; i < N + 1; i++) {
            for (int j = 1; j < N + 1; j++) {
                for (int k = 1; k < N + 1; k++) {
                    temp[i][j] += ((res[i][k] * a[k][j]) % 1000);
                }
            }
        }
        res = temp;
    }

    for (int i = 1; i < N + 1; i++) {
        for (int j = 1; j < N + 1; j++) {
            res[i][j] %= 1000;
        }
    }

    return res;
}

matrix_t unitMatrix(int N) {
    matrix_t S(N + 1, vector<int>(N + 1));
    for (int i = 1; i < N + 1; i++)
        for (int j = 1; j < N + 1; j++)
            S[i][j] = (i == j) ? 1 : 0;
    return S;
}

void print(matrix_t S, int N) {
    for (int i = 1; i < N + 1; i++) {
        for (int j = 1; j < N + 1; j++) {
            cout << S[i][j];
            if (j != N) cout << " ";
        }
        cout << endl;
    }
}
