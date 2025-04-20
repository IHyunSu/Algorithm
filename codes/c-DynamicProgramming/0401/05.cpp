// Triangle Path (2): Find Optimal Solution

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

typedef pair<int, vector<int>> Result;

// y, x 위치에서 시작했을 때 최대 합과 경로를 구함
Result path3(int y, int x, const vector<vector<int>>& triangle, vector<vector<Result>>& dp) {
    int n = triangle.size();

    // 맨 아래에 도달했을 경우
    if (y == n - 1) {
        return make_pair(triangle[y][x], vector<int>{triangle[y][x]});
    }

    // 이미 계산한 경우 반환
    if (dp[y][x].first != -1) {
        return dp[y][x];
    }

    // 왼쪽, 오른쪽 아래 경로 계산
    Result left = path3(y + 1, x, triangle, dp);
    Result right = path3(y + 1, x + 1, triangle, dp);

    Result best;
    if (right.first >= left.first) {
        best.first = triangle[y][x] + right.first;
        best.second.push_back(triangle[y][x]);
        best.second.insert(best.second.end(), right.second.begin(), right.second.end());
    } else {
        best.first = triangle[y][x] + left.first;
        best.second.push_back(triangle[y][x]);
        best.second.insert(best.second.end(), left.second.begin(), left.second.end());
    }

    dp[y][x] = best;
    return best;
}

int main() {
    int c;
    cin >> c;

    while (c--) {
        int n;
        cin >> n;

        vector<vector<int>> triangle(n);
        for (int i = 0; i < n; i++) {
            triangle[i].resize(i + 1);
            for (int j = 0; j <= i; j++) {
                cin >> triangle[i][j];
            }
        }

        // dp[y][x] = pair<합, 경로>
        vector<vector<Result>> dp(n, vector<Result>(n, make_pair(-1, vector<int>())));

        Result result = path3(0, 0, triangle, dp);

        // 출력: 최대 합
        cout << result.first << endl;

        // 출력: 경로
        for (int i = 0; i < result.second.size(); i++) {
            cout << result.second[i];
            if (i != result.second.size() - 1)
                cout << " ";
        }
        cout << endl;
    }

    return 0;
}
