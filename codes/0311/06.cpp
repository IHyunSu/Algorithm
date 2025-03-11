#include <iostream>

using namespace std;

void collatzCnt(int n, int& cnt);
void collatzPrint(int n);

int main () {
    int n, m, cnt = 0, max = 0, location = 0;
    cin >> n >> m;

    for (int i = n; i <= m; i++) {
        cnt = 0;
        collatzCnt(i, cnt);
        if (max <= cnt) {
            max = cnt;
            location = i;
        }
    }

    cout << location << " " << max << endl;
    collatzPrint(location);
}

void collatzCnt(int n, int& cnt) {
    if (n == 1) {
        cnt++;
    } else {
        while (n != 1) {
            if (n % 2 == 0) {
                n /= 2;
            } else {
                n = 3 * n + 1;
            }
            cnt++;
        }
    }
}

void collatzPrint(int n) {
    cout << n << " ";
    if (n == 1) {
        cout << n << endl;
    } else {
        while (n != 1) {
            if (n % 2 == 0) {
                n /= 2;
            } else {
                n = 3 * n + 1;
            }
            if (n != 1) cout << n << " ";
            else cout << n << endl;
        }
    }
}