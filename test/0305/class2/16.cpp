// 10845

#include <iostream>
#include <queue>
#include <string>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;
    string command;
    queue<int> q;

    for (int i = 0; i < n; i++) {
        cin >> command;
        if (command == "push") {
            int num;
            cin >> num;
            q.push(num);
        } 
        else if (command == "pop") {
            if (q.empty()) {
                cout << -1 << '\n';
            } else {
                cout << q.front() << '\n';
                q.pop();
            }
        } 
        else if (command == "size") {
            cout << q.size() << '\n';
        } 
        else if (command == "empty") {
            cout << (q.empty() ? 1 : 0) << '\n';
        } 
        else if (command == "front") {
            if (q.empty()) {
                cout << -1 << '\n';
            } else {
                cout << q.front() << '\n';
            }
        } 
        else if (command == "back") {
            if (q.empty()) {
                cout << -1 << '\n';
            } else {
                cout << q.back() << '\n';
            }
        }
    }
}
