// 8958

#include <iostream>
#include <vector>
#include <string.h>
using namespace std;

int main () {
    int N, cnt = 0, result = 0;
    cin >> N;
    string temp;

    for (int i = 0; i < N; i++) {
        cnt = 0;
        result = 0;
        cin >> temp;
        for (const char ch : temp) {
            if (ch == 'O') {
                cnt++;
                result += cnt;
            } else {
                cnt = 0;
            }
        }
        cout << result << endl;
    }
}