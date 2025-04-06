#include <iostream>
#include <vector>
#include <utility>

using namespace std;

void arrInput(vector<int>& S, int n);
void quicksort(int low, int high, vector<int>& S, int& cnt);
void partition(int low, int high, int& pivotpoint, vector<int>& S, int& cnt);

int main () {
    int n, cnt = 0;
    cin >> n;
    vector<int> S(n + 1);

    arrInput(S, n);

    quicksort(1, n, S, cnt);

    for (int i = 1; i < n + 1; i++) {
        cout << S[i];
        if (i != n) cout << " ";
    }
    cout << endl << cnt << endl;
}

void arrInput(vector<int>& S, int n) {
    for (int i = 1; i < n + 1; i++) {
        cin >> S[i];
    }
}

void quicksort(int low, int high, vector<int>& S, int& cnt) {
    int pivotpoint;

    if (low < high) {
        partition(low, high, pivotpoint, S, cnt);
        quicksort(low, pivotpoint - 1, S, cnt);
        quicksort(pivotpoint + 1, high, S, cnt);
    }
}

void partition(int low, int high, int& pivotpoint, vector<int>& S, int& cnt) {
    int pivotitem = S[low];

    int j = low;
    for (int i = low + 1; i <= high; i++) {
        if (S[i] < pivotitem) {
            j++;
            swap(S[i], S[j]);
            cnt++;
        }
    }
    pivotpoint = j;
    swap(S[low], S[pivotpoint]);
    cnt++;
}
