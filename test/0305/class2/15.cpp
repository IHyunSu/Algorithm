// 10823

#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {
    int n;
    cin >> n;
    string command;
    vector<int> stack;

    for (int i = 0; i < n; i++) {
        cin >> command;
        if (command == "push") {
            int num;
            cin >> num;
            stack.push_back(num);
        } 
        else if (command == "pop") {
            if (stack.empty()) {
                cout << -1 << '\n';
            } else {
                cout << stack.back() << '\n';
                stack.pop_back();
            }
        } 
        else if (command == "size") {
            cout << stack.size() << '\n';
        } 
        else if (command == "empty") {
            cout << (stack.empty() ? 1 : 0) << '\n';
        } 
        else if (command == "top") {
            if (stack.empty()) {
                cout << -1 << '\n';
            } else {
                cout << stack.back() << '\n';
            }
        }
    }
}
