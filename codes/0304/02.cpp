// #include <iostream>
// using namespace std;
// #define MAX_SIZE 101

// int main () {
//     int n, number, sum = 0;
//     int arr[MAX_SIZE] = {0, };

//     cin >> n;

//     for (int i = 0; i < n; i++)
//         cin >> arr[i];

//     for (int i = 0; i < n; i++)
//         sum += arr[i];

//     cout << sum;
// }

#include <iostream>
#include <vector>
using namespace std;

int sumArray(vector<int>& S, int n);

int main () {
    int n;
    cin >> n;
    vector<int> S(n);

    for (int i = 0; i < n; i++) {
        cin >> S[i];
    }

    cout << sumArray(S, n);
}

int sumArray(vector<int>& S, int n) {
    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += S[i];
    }

    return sum;
}