// 11651

// 0516 Lee Hyun Su , Lang : c++

// 좌표 정렬하기 2
/**
 * y좌표가 증가하는 순으로, y좌표가 같으면 x좌표가 증가하는 순으로
 */

#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <vector>
using namespace std;

typedef vector<pair<int,int>> pair_t;

int main () {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int N;
    cin >> N;

    pair_t arr(N);
    for (int i = 0; i < N; i++)
        cin >> arr[i].first >> arr[i].second;

    sort(arr.begin(), arr.end(), [](const pair<int, int>& a, const pair<int, int>& b) {
        if (a.second < b.second) {
            return true;
        } else if (a.second == b.second) {
            return a.first < b.first;
        } else {
            return false;
        }
    });

    for (int i = 0; i < N; i++) {
        printf("%d %d\n", arr[i].first, arr[i].second);
    }

    return 0;
}