// Triangle Path (1): Find Optimal Value

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int path3(int y, int x, const vector<vector<int>>& triangle, vector<vector<int>>& cache) {
    int n = triangle.size();

    // 맨 아래에 도달했을 경우
    if (y == n - 1)
        return triangle[y][x];

    // 이미 계산한 경우
    if (cache[y][x] != -1)
        return cache[y][x];

    // 아래 또는 아래 오른쪽 중 큰 값 선택
    cache[y][x] = triangle[y][x] + max(
        path3(y + 1, x, triangle, cache),
        path3(y + 1, x + 1, triangle, cache)
    );

    return cache[y][x];
}

int main() {
    int c;
    cin >> c;  // 테스트 케이스 수

    while (c--) {
        int n;
        cin >> n;

        vector<vector<int>> triangle(n);
        vector<vector<int>> cache(n, vector<int>(n, -1));

        for (int i = 0; i < n; i++) {
            triangle[i].resize(i + 1);
            for (int j = 0; j <= i; j++) {
                cin >> triangle[i][j];
            }
        }

        cout << path3(0, 0, triangle, cache) << endl;
    }

    return 0;
}
