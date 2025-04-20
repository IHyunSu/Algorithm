#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;

    // 회의 시작 시간과 종료 시간 쌍을 저장
    vector<pair<int, int> > meetings(n);

    for (int i = 0; i < n; i++) {
        cin >> meetings[i].first >> meetings[i].second; // 시작, 종료 시간 입력
    }

    vector<pair<int, int> > selected;
    int last_end = 0;

    for (int i = 0; i < n; i++) {
        int start = meetings[i].first;
        int end = meetings[i].second;
        if (start >= last_end) {
            selected.push_back({start, end});
            last_end = end;
        }
    }

    // 출력
    cout << selected.size() << endl;
    for (int i = 0; i < selected.size(); i++) {
        cout << selected[i].first << " " << selected[i].second << endl;
    }

    return 0;
}
