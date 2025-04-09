#include <iostream>
using namespace std;

typedef long long long_t;

long_t fun(long_t n) {
    long_t i, j, cnt = 0;
    // cnt = ((4 * n) / 2) * n;
    cnt = 2 * n * n;
    // for (i=1; i<=4*n; i+=2)
    //     for (j=n; j>=1; j--)
    //         cnt++;
    return cnt;
}

int main() {
    long_t n;
    scanf("%lld", &n);
    printf("%lld", fun(n));
}