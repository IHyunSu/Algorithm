#include <iostream>
#include <vector>

using namespace std;

int N, indexing = 0;
string quadtree;
vector<vector<int> > image;

// 재귀적으로 Quadtree 문자열을 복원하는 함수
void decode(int x, int y, int size) {
    char c = quadtree[indexing++]; // 현재 처리할 문자

    if (c == 'w' || c == 'b') {
        int value = (c == 'b') ? 1 : 0;
        for (int i = x; i < x + size; i++) {
            for (int j = y; j < y + size; j++) {
                image[i][j] = value;
            }
        }
    } else { // 'x'인 경우 4분할 재귀
        int half = size / 2;
        decode(x, y, half);         // 1사분면 (왼쪽 위)
        decode(x, y + half, half);  // 2사분면 (오른쪽 위)
        decode(x + half, y, half);  // 3사분면 (왼쪽 아래)
        decode(x + half, y + half, half); // 4사분면 (오른쪽 아래)
    }
}

int main() {
    cin >> N >> quadtree;
    image.assign(N, vector<int>(N, 0)); // N x N 배열 초기화

    decode(0, 0, N); // 0,0에서 시작하여 N*N 복원

    // 결과 출력
    cout << N << endl;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cout << image[i][j];
            if (j != N - 1) cout << " "; // 마지막 공백 제거
        }
        cout << endl;
    }

    return 0;
}
