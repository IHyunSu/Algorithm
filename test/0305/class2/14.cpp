#include <iostream>
using namespace std;

const int OFFSET = 1000000;
const int MAX = 2000001;

int cnt[MAX];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;

    int num;
    for (int i = 0; i < n; i++) {
        cin >> num;
        cnt[num + OFFSET]++;
    }

    for (int i = 0; i < MAX; i++) {
        while (cnt[i]--) {
            cout << (i - OFFSET) << '\n';
        }
    }

    return 0;
}
