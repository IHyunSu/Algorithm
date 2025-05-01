//10250

#include <iostream>
#include <vector>

using namespace std;
typedef vector<vector<int> > matrix_t;

void findLocation(int N, int W, int H, int& locationH, int& locationW);

int main () {
    int number;
    int H, W, N;
    cin >> number;
    int cnt = 0;
    int locationH = 0, locationW = 0;

    for (int i = 0; i < number; i++) {
        cin >> H >> W >> N;
        findLocation(N, W, H, locationH, locationW);
        if (locationW < 10) {
            cout << locationH << "0" << locationW << endl;
        } else {
            cout << locationH << locationW << endl;
        }
    }


}

void findLocation(int N, int W, int H, int& locationH, int& locationW) {
    int cnt = 0;
    for (int i = 1; i <= W; i++) {
        for (int j = 1; j <= H; j++) {
            if (cnt != N) {
                locationH = j;
                locationW = i;
                cnt++;
            } else {
                return;
            }
        }
    }
    
}