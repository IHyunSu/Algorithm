#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

bool compare(const string &a, const string &b) {
    if (a.length() != b.length())
        return a.length() < b.length();
    else
        return a < b;
}

int main() {
    int n;
    cin >> n;
    
    vector<string> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    
    sort(arr.begin(), arr.end(), compare);
    arr.erase(unique(arr.begin(), arr.end()), arr.end());

    for (const string &s : arr) {
        cout << s << endl;
    }

    return 0;
}
