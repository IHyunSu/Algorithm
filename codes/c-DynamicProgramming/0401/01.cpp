// Binomial Coefficient: Tabulation

#include <iostream>
#include <vector>
using namespace std;

typedef unsigned long long LongInteger;
typedef vector<vector<LongInteger> > matrix_t;

// LongInteger bin2(int n, int k) {
//     matrix_t B(n + 1, vector<LongInteger>(n + 1));
//     for (int i = 0; i <= n; i++) {
//         for (int j = 0; j <= min(i, k); j++) {
//             if (j == 0 || j == i)
//                 B[i][j] = 1;
//             else
//                 B[i][j] = (B[i - 1][j] + B[i - 1][j - 1]) % 10007;
//         }
//     }
//     return B[n][k];
// }

LongInteger bin3(int n, int k) {
    vector<LongInteger> B(n + 1);
    if (k > n / 2)
        k = n - k;
    B[0] = 1;
    for (int i = 1; i < n + 1; i++) {
        int j = min(i, k);
        while (j > 0) {
            B[j] = (B[j] + B[j - 1]) % 10007;
            j -= 1;
        }
    }
    return B[k];
}

int main () {
    int n, k;
    cin >> n >> k;

    LongInteger result = bin3(n, k);

    cout << result << endl;

    return 0;
}