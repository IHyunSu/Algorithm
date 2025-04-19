#include <iostream>
#include <vector>
#include <string>
using namespace std;

void lcs(const string& x, const string& y, vector<vector<int> >& c, vector<vector<int> >& b) {
    int m = x.length();
    int n = y.length();
    c.assign(m + 1, vector<int>(n + 1, 0));
    b.assign(m + 1, vector<int>(n + 1, 0));

    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (x[i - 1] == y[j - 1]) {
                c[i][j] = c[i - 1][j - 1] + 1;
                b[i][j] = 1;
            } else {
                if (c[i][j - 1] > c[i - 1][j]) {
                    c[i][j] = c[i][j - 1];
                    b[i][j] = 2;
                } else {
                    c[i][j] = c[i - 1][j];
                    b[i][j] = 3;
                }
            }
        }
    }
}

string get_lcs(int i, int j, const vector<vector<int> >& b, const string& x) {
    if (i == 0 || j == 0) return "";
    if (b[i][j] == 1)
        return get_lcs(i - 1, j - 1, b, x) + x[i - 1];
    else if (b[i][j] == 2)
        return get_lcs(i, j - 1, b, x);
    else
        return get_lcs(i - 1, j, b, x);
}

int main() {
    string x, y;
    cin >> x >> y;

    vector<vector<int> > c, b;
    lcs(x, y, c, b);

    string lcs_str = get_lcs(x.length(), y.length(), b, x);
    int LCS_len = lcs_str.length();

    if (LCS_len == 0) cout << 0 << endl;
    else {
        cout << LCS_len << endl;
        cout << lcs_str << endl;
    }

    return 0;
}