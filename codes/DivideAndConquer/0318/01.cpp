// Divide And Conquer (1)

#include <iostream>
#include <vector>
#include <utility>

using namespace std;

void arrInput(vector<int>& S, int n);
void arrSort(vector<int>& S, int n);
int binsearch2(int low, int high, int x, vector<int> S, int& cnt);

int main () {
    int n, m, location = 0, x, cnt = 0;
    cin >> n >> m;
    vector<int> S(n + 1);
    arrInput(S, n);

    for (int i = 0; i < m; i++) {
        cin >> x;
        cnt = 0;
        location = binsearch2(1, n, x, S, cnt);
        cout << cnt << " " << location << endl;
    }
}

void arrSort(vector<int>& S, int n) {
    for (int i = 1; i < n + 1; i++) {
        for (int j = i + 1; j < n + 1; j++) {
            if (S[i] > S[j]) {
                swap(S[i], S[j]);
            }
        }
    }
}

void arrInput(vector<int>& S, int n) {
    for (int i = 1; i < n + 1; i++) {
        cin >> S[i];
    }

    arrSort(S, n);
}

int binsearch2(int low, int high, int x, vector<int> S, int& cnt) {
    int mid;
    cnt++;
    if (low > high)
        return 0;
    else {
        mid = (low + high) / 2;
        if (x == S[mid])
            return mid;
        else if (x < S[mid])
            return binsearch2(low, mid - 1, x, S, cnt);
        else // x > S[mid]
            return binsearch2(mid + 1, high, x, S, cnt);
    }
}