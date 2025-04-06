#include <iostream>
#include <vector>
using namespace std;
typedef unsigned long long LongInt;

LongInt fib2 (LongInt n);

int main () {
    LongInt n;
    cin >> n;

    cout << fib2(n);
}

LongInt fib2 (LongInt n) {
    vector<LongInt> F;
    if (n <= 1) {
        return n;
    } else {
        F.push_back(0);
        F.push_back(1);
        for (int i = 2; i <= n; i++) {
            F.push_back((F[i-1] + F[i-2]) % 1000000);
        }
        return F[n];
    }
}