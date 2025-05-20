#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <map>

using namespace std;

int main() {
    int N;
    cin >> N;
    vector<int> arr(N);
    int sum = 0;

    for (int i = 0; i < N; ++i) {
        cin >> arr[i];
        sum += arr[i];
    }

    // Sort for median and mode
    sort(arr.begin(), arr.end());

    // Arithmetic mean (rounded)
    int mean = round((double)sum / N);
    cout << mean << endl;

    // Median
    cout << arr[N / 2] << endl;

    // Mode
    map<int, int> freq;
    int max_freq = 0;
    for (int num : arr) {
        freq[num]++;
        max_freq = max(max_freq, freq[num]);
    }

    vector<int> modes;
    for (auto& p : freq) {
        if (p.second == max_freq) {
            modes.push_back(p.first);
        }
    }

    sort(modes.begin(), modes.end());
    if (modes.size() >= 2)
        cout << modes[1] << endl; // second smallest
    else
        cout << modes[0] << endl;

    // Range
    cout << arr.back() - arr.front() << endl;

    return 0;
}
