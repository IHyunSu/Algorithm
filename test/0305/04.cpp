// 2577

#include <iostream>
#include <vector>
#include <string.h>

using namespace std;

int main () {
    int A, B, C;

    cin >> A >> B >> C;

    int product = A * B * C;
    string str_num = to_string(product);
    char char_nums[1001];
    strcpy(char_nums, str_num.c_str());

    vector<int> S(10);

    for (int i = 0; i < 10; i++) S[i] = 0;

    for (int i = 0; i < str_num.size(); i++) {
        for (int j = 0; j < 10; j++) {
            if ((int(char_nums[i]) - '0') == j) {
                S[j]++;
            }
        }
    }

    for (int i = 0; i < 10; i++) {
        cout << S[i] << endl;
    }
}