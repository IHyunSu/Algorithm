#include <iostream>
#include <vector>
using namespace std;
#define MAX_SIZE 101
#define SWAP(temp, a, b) { \
    temp = a; \
    a = b; \
    b = temp; \
}

void exchangeSort(int n, vector<int>& S);
void binarySearch(int n, vector<int>& S, int x, int& location);

int main () {
    int n, m, target, index = 0;
    cin >> n >> m;
    vector<int>arr(n);

    for (int i = 0; i < n; i++)
        cin >> arr[i];

    exchangeSort(n, arr);


    for (int i = 0; i < m; i++) {
        cin >> target;
        
        binarySearch(n, arr, target, index);
        if (index != -1) {
            cout << target << " is in " << index + 1 << "." << endl;
        } else {
            cout << target << " is not in S." << endl;
        }
    }

}

void exchangeSort(int n, vector<int>& S) {
    int temp;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (S[i] > S[j]) {
                SWAP(temp, S[i], S[j]);
            }
        }
    }
}

void binarySearch(int n, vector<int>& S, int x, int& location) {
    int low, high, mid;
    low = 0; high = n - 1;
    location = -1;
    while (low <= high && location == -1) {
        mid = (low + high) / 2;
        if (x == S[mid]) {
            location = mid;
            return;
        }
        else if (x < S[mid])
            high = mid - 1;
        else
            low = mid + 1;
    }
}