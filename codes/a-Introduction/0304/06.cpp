#include <iostream>
using namespace std;
typedef unsigned long long LongInt;

LongInt fib (LongInt n, LongInt& cnt);

int main () {
    LongInt n, cnt = 0;
    cin >> n;

    cout << fib(n, cnt) << endl;
    cout << cnt << endl;
}

LongInt fib (LongInt n, LongInt& cnt) {
    cnt++;
    if (n <= 1) {
        return n;
    } else {
        return fib(n-1, cnt) + fib(n-2, cnt);
    }
}