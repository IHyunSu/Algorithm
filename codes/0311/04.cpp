#include <iostream>
using namespace std;

typedef long long long_t;

long_t fun(long_t n) {
    if (n == 0)
        return 1;
    else {
        long_t s = 0;
        s += 8 * fun(n/4);
        return s;
    }
}

int main() {
    long_t n;
    scanf("%lld", &n);
    printf("%lld", fun(n));
}