#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

typedef vector<vector<int> > Matrix;

int cnt = 0;
int Threshold = 1;

int check_power_of_2(int N);
Matrix add_zero(Matrix &M, int idx, int N);
void print_matrix(int N, const Matrix &M);
void partition(int m, const Matrix &M, Matrix &M11, Matrix &M12, Matrix &M21, Matrix &M22);
void mmult(int N, const Matrix &A, const Matrix &B, Matrix &C);
void madd(int N, const Matrix &A, const Matrix &B, Matrix &C);
void msub(int N, const Matrix &A, const Matrix &B, Matrix &C);
void combine(int m, Matrix &C, const Matrix &C11, const Matrix &C12, const Matrix &C21, const Matrix &C22);
void strassen(int N, Matrix &A, Matrix &B, Matrix &C);

int main() {
    int N;
    cin >> N >> Threshold;
    int k = check_power_of_2(N);
    int idx = k - N;
    Matrix A(N, vector<int>(N)), B(N, vector<int>(N)), C(k, vector<int>(k, 0));
    for (auto &row : A) for (auto &elem : row) cin >> elem;
    for (auto &row : B) for (auto &elem : row) cin >> elem;
    if (idx != 0) {
        A = add_zero(A, idx, N);
        B = add_zero(B, idx, N);
    }
    strassen(k, A, B, C);
    cout << cnt << endl;
    print_matrix(N, C);
    return 0;
}

//
//  2의 제곱인지 판단하는 함수
//

int check_power_of_2(int N) {
    if ((N & -N) == N) {        // 2의 제곱수들의 이진수는 모두, 맨 앞자리 1 이외 0이다. ex) 2 = 10 , 4 = 100, 8 = 1000
        return N;               
    } else {
        int k = 1;
        while (k < N) {
            k *= 2;
        }
        return k;
    }
}

Matrix add_zero(Matrix &M, int idx, int N) {
    for (int i = 0; i < N; i++) {
        M[i].resize(N + idx, 0);
    }
    M.resize(N + idx, vector<int>(N + idx, 0));
    return M;
}

void print_matrix(int N, const Matrix &M) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cout << M[i][j];
            if (j != N - 1) cout << " "; 
        }
        cout << endl;
    }
}

void partition(int m, const Matrix &M, Matrix &M11, Matrix &M12, Matrix &M21, Matrix &M22) {
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < m; j++) {
            M11[i][j] = M[i][j];
            M12[i][j] = M[i][j + m];
            M21[i][j] = M[i + m][j];
            M22[i][j] = M[i + m][j + m];
        }
    }
}

void mmult(int N, const Matrix &A, const Matrix &B, Matrix &C) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            for (int k = 0; k < N; k++) {
                C[i][k] += A[i][j] * B[j][k];
            }
        }
    }
}

void madd(int N, const Matrix &A, const Matrix &B, Matrix &C) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            C[i][j] = A[i][j] + B[i][j];
        }
    }
}

void msub(int N, const Matrix &A, const Matrix &B, Matrix &C) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            C[i][j] = A[i][j] - B[i][j];
        }
    }
}

void combine(int m, Matrix &C, const Matrix &C11, const Matrix &C12, const Matrix &C21, const Matrix &C22) {
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < m; j++) {
            C[i][j] = C11[i][j];
            C[i][j + m] = C12[i][j];
            C[i + m][j] = C21[i][j];
            C[i + m][j + m] = C22[i][j];
        }
    }
}

void strassen(int N, Matrix &A, Matrix &B, Matrix &C) {
    cnt++;  
    if (N <= Threshold) {
        mmult(N, A, B, C);
    } else {
        int m = N / 2;
        Matrix A11(m, vector<int>(m)), A12(m, vector<int>(m)), A21(m, vector<int>(m)), A22(m, vector<int>(m));
        Matrix B11(m, vector<int>(m)), B12(m, vector<int>(m)), B21(m, vector<int>(m)), B22(m, vector<int>(m));
        Matrix C11(m, vector<int>(m)), C12(m, vector<int>(m)), C21(m, vector<int>(m)), C22(m, vector<int>(m));
        Matrix M1(m, vector<int>(m)), M2(m, vector<int>(m)), M3(m, vector<int>(m)), M4(m, vector<int>(m)), M5(m, vector<int>(m)), M6(m, vector<int>(m)), M7(m, vector<int>(m));
        Matrix L(m, vector<int>(m)), R(m, vector<int>(m));
        
        partition(m, A, A11, A12, A21, A22);
        partition(m, B, B11, B12, B21, B22);
        
        madd(m, A11, A22, L); madd(m, B11, B22, R); strassen(m, L, R, M1);
        madd(m, A21, A22, L); strassen(m, L, B11, M2);
        msub(m, B12, B22, R); strassen(m, A11, R, M3);
        msub(m, B21, B11, R); strassen(m, A22, R, M4);
        madd(m, A11, A12, L); strassen(m, L, B22, M5);
        msub(m, A21, A11, L); madd(m, B11, B12, R); strassen(m, L, R, M6);
        msub(m, A12, A22, L); madd(m, B21, B22, R); strassen(m, L, R, M7);
        
        madd(m, M1, M4, L); msub(m, L, M5, L); madd(m, L, M7, C11);
        madd(m, M3, M5, C12);
        madd(m, M2, M4, C21);
        madd(m, M1, M3, L); msub(m, L, M2, L); madd(m, L, M6, C22);
        
        combine(m, C, C11, C12, C21, C22);
    }
}
