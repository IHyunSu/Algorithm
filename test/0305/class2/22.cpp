// 2863

#include <iostream>
#include <vector>
using namespace std;

int main () {
    int a, b, v;
    cin >> a >> b >> v;
    if (v < a) {cout << "1" << endl;
    }
    else {
        if ((v - a) % (a - b) == 0) {
            cout << ((v - a) / (a - b) + 1);
        } else {
            cout << ((v - a) / (a - b) + 2);
        }
    }
}