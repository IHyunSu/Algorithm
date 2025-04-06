#include <iostream>
#include <cmath>
using namespace std;

typedef long long long_t;

long_t fun(long_t n, long_t m, long_t p) {
    long_t i, j, k, cnt = 0, cntI = 0, cntJ = 0, cntK = 0;
    cntI = (2 * n + 3) / 4;
    cntJ = log2(2 * m) + 1;
    cntK = log2(4 * p) + 1; 
    cnt = cntI * cntJ * cntK;
    return cnt;
}

int main() {
    long_t n, m, p;
    scanf("%lld %lld %lld", &n, &m, &p);
    printf("%lld", fun(n, m, p));
}