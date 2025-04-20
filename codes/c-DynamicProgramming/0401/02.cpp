// Binomial Coefficient: Memoization

#include <iostream>
#include <vector>
using namespace std;

typedef unsigned long long LongInteger;
typedef vector<vector<LongInteger> > matrix_t;
LongInteger call_count = 0;
matrix_t B;

LongInteger binom(int n, int k) {
    call_count++;
    if (k == 0 || k == n) {
        return 1;
    } else if (B[n][k] != -1) {
        return B[n][k];
    } else {
        B[n][k] = (binom(n - 1, k - 1) + binom(n - 1, k)) % 10007;
        return B[n][k];
    }
}

int main () {
    int n, k;
    cin >> n >> k;

    B.assign(n + 1, vector<LongInteger>(k + 1, -1));
    LongInteger result = binom(n, k);

    cout << result << endl;
    cout << call_count << endl;
}