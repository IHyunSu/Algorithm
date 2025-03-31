#include <iostream>
#include <vector>

using namespace std;

int N;
vector<vector<int> > image;

string quadtree(int x, int y, int size) {
    // 첫 번째 픽셀을 기준으로 동일한 값인지 확인
    int first_pixel = image[x][y];
    bool isUniform = true;
    
    for (int i = x; i < x + size; i++) {
        for (int j = y; j < y + size; j++) {
            if (image[i][j] != first_pixel) {
                isUniform = false;
                break;
            }
        }
        if (!isUniform) break;
    }

    // 만약 모든 픽셀이 동일하다면 해당 값을 반환
    if (isUniform) {
        return first_pixel == 1 ? "b" : "w";
    }

    // 0과 1이 섞여 있다면 'x'를 추가하고 4분할
    int half = size / 2;
    return "x" +
           quadtree(x, y, half) +         // 1사분면 (왼쪽 위)
           quadtree(x, y + half, half) +  // 2사분면 (오른쪽 위)
           quadtree(x + half, y, half) +  // 3사분면 (왼쪽 아래)
           quadtree(x + half, y + half, half); // 4사분면 (오른쪽 아래)
}

int main() {
    cin >> N;
    image.resize(N, vector<int>(N));

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> image[i][j];
        }
    }

    cout << quadtree(0, 0, N) << endl;
    return 0;
}
