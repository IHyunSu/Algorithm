// #include <iostream>
// using namespace std;
// #define MAX_SIZE 101
// #define SWAP(temp, a, b) { \
//     temp = a; \
//     a = b; \
//     b = temp; \
// }

// int main () {
//     int count = 0, n, temp;
//     int arr[MAX_SIZE] = {0, };

//     cin >> n;

//     for (int i = 0; i < n; i++)
//         cin >> arr[i];

//     for (int i = 0; i < n; i++) {
//         for (int j = i + 1; j < n; j++) {
//             if (arr[i] > arr[j]) {
//                 SWAP(temp, arr[i], arr[j]);
//                 count++;
//             }
//         }
//     }

//     for (int i = 0; i < n; i++) {
//         if (i != n - 1) {
//             cout << arr[i] << " ";
//         } else {
//             cout << arr[i] << endl;
//         }
//     }

//     cout << count;
// }

// #include <iostream>
// #include <vector>
// using namespace std;
// #define SWAP(temp, a, b) { \
//     temp = a; \
//     a = b; \
//     b = temp; \
// }

// int exchangeSort(vector<int>& S, int n);
// void printArray(vector<int>&S, int n);

// int main () {
//     int n;
//     cin >> n;
//     vector<int> S(n);

//     for (int i = 0; i < n; i++)
//         cin >> S[i];

//     int cnt = exchangeSort(S, n);

//     printArray(S, n);
//     cout << cnt << endl;
// }

// int exchangeSort(vector<int>& S, int n) {
//     int cnt = 0, temp;
//     for (int i = 0; i < n; i++) {
//         for (int j = i + 1; j < n; j++) {
//             if (S[i] > S[j]) {
//                 SWAP(temp, S[i], S[j]);
//                 cnt++;
//             }
//         }
//     }
//     return cnt;
// }

// void printArray(vector<int>&S, int n) {
//     for (int i = 0; i < n; i++) {
//         if (i != n - 1) cout << S[i] << " ";
//         else cout << S[i] << endl;
//     }
// }

#include <iostream>
#include <vector>
#include <utility> // swap함수
using namespace std;

void inputArray(vector<int>& S, int n); // call by reference
void exchangeSort(vector<int>& S, int n);
void printArray(vector<int> S, int n);

int main () {
    int n;
    cin >> n;
    vector<int>S(n+1);

    inputArray(S, n);
    exchangeSort(S, n);
    printArray(S, n);

    return 0;
}

void inputArray(vector<int>& S, int n) {
    for (int i = 1; i <= n; i++) {
        cin >> S[i];
    }
}

void exchangeSort(vector<int>& S, int n) {
    for (int i = 1; i <= n; i++) {
        for (int j = i + 1; j <= n; j++) {
            if (S[i] > S[j]) {
                swap(S[i], S[j]);
            }
        }
    }

    return;
}

void printArray(vector<int> S, int n) {
    for (int i = 1; i <= n; i++) {
        cout << S[i];
        if (i != n) cout << " "; 
    }

    return;
}

//의와 평화의 입맞춤