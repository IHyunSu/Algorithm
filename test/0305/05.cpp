//2920

#include <iostream>
#include <vector>

using namespace std;

int main () {
    vector<int> R1(9);
    vector<int> R2(9);
    vector<int> TEST(9);
    int test1 = 1, test2 = 1;

    for (int i = 1; i <= 8; i++) R1[i] = i;
    for (int i = 1; i <= 8; i++) R2[i] = 9 - i;

    for (int i = 1; i <= 8; i++) cin >> TEST[i];

    for (int i = 1; i <= 8; i++) {
        if (R1[i] != TEST[i]) {
            test1 = 0;
            break;
        }
    }

    for (int i = 1; i <= 8; i++) {
        if (R2[i] != TEST[i]) {
            test2 = 0;
            break;
        }
    }

    if (test1 == 1) {
        cout << "ascending" << endl;
    } else if (test2 == 1) {
        cout << "descending" << endl;
    } else if (test1 != 1 && test2 != 1) {
        cout << "mixed" << endl;
    }
}