// #include <iostream>
// using namespace std;
// #define MAX_SIZE 101

// #define SWAP(temp, a, b) { \
//     temp = a; \
//     a = b; \
//     b = temp; \
// }

// int main () {
//     int n, m, number, temp, target, check = 0;
//     int arr[MAX_SIZE] = {0, };
//     cin >> n >> m;

//     for (int i = 0; i < n; i++) {
//         cin >> number;
//         arr[i] = number;
//     }

//     for (int i = 0; i < m; i++) {
//         check = 0;
//         cin >> target;
//         for (int j = 0; j < n; j++) {
//             if (arr[j] == target) {
//                 check = 1;
//                 temp = j+1;
//             }
//         }
//         if (check == 1) {
//             cout << target << " is in " << temp << "." << endl;
//         }
//         else {
//             cout << target << " is not in S." << endl; 
//         }
//     }
// }


#include <iostream>
#include <vector>
using namespace std;

void findX(vector<int>& S, int n, int x, int& location);

int main () {
    int n, m, x, location = 0;
    
    cin >> n >> m;
    vector<int> S(n);

    for (int i = 0; i < n; i++) {
        cin >> S[i];
    }

    for (int i = 0; i < m; i++) {
        cin >> x;
        location = -1;
        findX(S, n, x, location);
        if (location != -1)
            cout << x << " is in " << location+1 << "." << endl;
        else
            cout << x << " is not in S." << endl;
    }
}

void findX(vector<int>& S, int n, int x, int& location) {
    for (int i = 0; i < n; i++) {
        if (S[i] == x) {
            location = i;
            return;
        }
    }
}