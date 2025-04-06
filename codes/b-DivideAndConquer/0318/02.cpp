#include <iostream>
#include <vector>

using namespace std;

void arrInput(vector<int>& S, int n);
void mergesort2(int low, int high, int& cnt, vector<int>& S);
void merge2(int low, int mid, int high, int& cnt, vector<int>& S);


int main () {
    int n, cnt = 0;
    cin >> n;
    vector<int> S(n + 1); // init
    arrInput(S, n);

    mergesort2(1, n, cnt, S);

    for (int i = 1; i < n + 1; i++) {
        cout << S[i];
        if (i != n) cout << " ";
    }
    cout << endl;

    cout << cnt << endl;
}

void arrInput(vector<int>& S, int n) {
    for (int i = 1; i < n + 1; i++) {
        cin >> S[i];
    }
}

void mergesort2(int low, int high, int& cnt, vector<int>& S) {
    if (low < high) {
        int mid = (low + high) / 2;
        mergesort2(low, mid, cnt, S);
        mergesort2(mid + 1, high, cnt, S);
        merge2(low, mid, high, cnt, S);
    }
}

void merge2(int low, int mid, int high, int& cnt, vector<int>& S) {
    int i = low, j = mid + 1, k = 0;
    vector<int> U(high - low + 1);
    cnt++;

    while (i <= mid && j <= high) {
        U[k++] = (S[i] < S[j]) ? S[i++] : S[j++];
    }
    if (i > mid) {
        while (j <= high) {
            U[k++] = S[j++];
        }
    }
    else {
        while (i <= mid) {
            U[k++] = S[i++];
        }
    }
    for (int t = low; t <= high; t++) {
        S[t] = U[t - low];
    }
}