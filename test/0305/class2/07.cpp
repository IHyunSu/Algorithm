//4153

#include <iostream>
#include <math.h>
using namespace std;

int main () {
    int a, b, c;
    int temp = 0;

    while (1) {
        cin >> a >> b >> c;

        if (a == 0 && b == 0 && c == 0) {
            break;
        }

        if (a > b) {
            temp = a;
            a = b;
            b = temp;
        }

        if (b > c) {
            temp = b;
            b = c;
            c = temp;
        }

        if (pow(c, 2) == (pow(a, 2) + pow(b, 2))) {
            cout << "right" << endl;
        } else {
            cout << "wrong" << endl;
        }
    }
}