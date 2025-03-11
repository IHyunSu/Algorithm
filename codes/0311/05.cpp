// #include <iostream>
// #include <vector>

// using namespace std;

// int main () {
//     int n;
//     cin >> n;

//     if (n == 1) {
//         cout << n << endl;
//     } else {
//         while (n != 1) {
//             if (n % 2 == 0) {
//                 n /= 2;
//             } else {
//                 n = 3 * n + 1;
//             }
//             cout << n << endl;
//         }
//     }
// }

#include <iostream>
using namespace std;

void collatz(int n);

int main () {
    int n;
    cin >> n;

    collatz(n);

    return 0;
}

void collatz(int n) {
    cout << n << endl;

    if (n == 1) {
        return;
    } else {
        if (n % 2 == 0) {
            collatz(n / 2);
        } else {
            collatz(3 * n + 1);
        }
    }
}