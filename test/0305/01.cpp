#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {
    vector<string> words(5);

    for (int i = 0; i < 5; i++) {
        cin >> words[i];
    }

    string result;
    int max_length = 0;

    for (const string& word : words) {
        if (word.length() > max_length) {
            max_length = word.length();
        }
    }

    for (int col = 0; col < max_length; col++) {
        for (int row = 0; row < 5; row++) {
            if (col < words[row].length()) {
                result += words[row][col];
            }
        }
    }

    cout << result << endl;
    return 0;
}
