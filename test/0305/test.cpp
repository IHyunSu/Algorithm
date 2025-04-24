#include <iostream>
#include <stdio.h>
using namespace std;
int cnt = 0;

void func10(int n);
void func11(int n);

int main () {
    int n;
    cin >> n;
    cout << "print(func10):" << endl;
    func10(n);
    cout << "call number(func10): " << cnt << endl;
    cnt = 0;
    cout << "print(func11):" << endl;
    func11(n);
    cout << "call number(func11): " << cnt << endl;
}
void func10(int n) {
    for (int i = 1; i <= n; i++) {
        for (int j = i; j <= n; j++) {
            cout << "*";
            if (j != n) cout << " ";
            cnt++;
        }
        cout << endl;
    }
}

void func11(int n) {
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j += i) {
            cout << "*";
            if (j != n) cout << " ";
            cnt++;
        }
        cout << endl;
    }
}