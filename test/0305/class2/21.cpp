#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool compare(const pair<int, int>& a, const pair<int, int>& b) {
    if (a.second == b.second) return a.first < b.first;
    return a.second < b.second;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    vector<pair<int, int>> meetings(n);

    for (int i = 0; i < n; i++) {
        cin >> meetings[i].first >> meetings[i].second;
    }

    sort(meetings.begin(), meetings.end(), compare);

    int last_end = 0;
    int count = 0;

    for (int i = 0; i < n; i++) {
        if (meetings[i].first >= last_end) {
            last_end = meetings[i].second;
            count++;
        }
    }

    cout << count << "\n";

    return 0;
}
