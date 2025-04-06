#include <iostream>
using namespace std;

const int MOD = 10007;

typedef struct {
    long long m[2][2];
} Matrix;

Matrix matrix_mult(Matrix A, Matrix B) {
    Matrix C;
    C.m[0][0] = (A.m[0][0] * B.m[0][0] + A.m[0][1] * B.m[1][0]) % MOD;
    C.m[0][1] = (A.m[0][0] * B.m[0][1] + A.m[0][1] * B.m[1][1]) % MOD;
    C.m[1][0] = (A.m[1][0] * B.m[0][0] + A.m[1][1] * B.m[1][0]) % MOD;
    C.m[1][1] = (A.m[1][0] * B.m[0][1] + A.m[1][1] * B.m[1][1]) % MOD;
    return C;
}

Matrix matrix_exponentiation(Matrix A, long long n) {
    Matrix result = {1, 0, 0, 1}; // Identity matrix
    while (n) {
        if (n % 2)
            result = matrix_mult(result, A);
        A = matrix_mult(A, A);
        n /= 2;
    }
    return result;
}

long long fibonacci(long long n) {
    if (n == 1) return 1;
    if (n == 2) return 1;
    
    Matrix F = {1, 1, 1, 0};
    Matrix result = matrix_exponentiation(F, n - 1);
    return result.m[0][0]; // F(n) value
}

int main() {
    long long N;
    cin >> N;
    cout << fibonacci(N) << endl;
    return 0;
}
