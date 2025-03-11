#include <iostream>
using namespace std;
void hanoi(int n, int m, char src, char via, char dst, int& cntA, int& cntB);

int main() {
    int n, m, cntA = 0, cntB = 0;
    cin >> n >> m;
    hanoi(n, m, 'A', 'B', 'C', cntA, cntB);
    cout << cntA;
}

void hanoi(int n, int m, char src, char via, char dst, int& cntA, int& cntB) {
    cntA++;
    if (n == 1) {
        cntB++;
        // printf("%c -> %c\n", src, dst);
        if (cntB == m) printf("%c -> %c\n", src, dst);
    }
    else {
        hanoi(n-1, m, src, dst, via, cntA, cntB);
        hanoi(1, m, src, via, dst, cntA, cntB);
        hanoi(n-1, m, via, src, dst, cntA, cntB);
    }
}