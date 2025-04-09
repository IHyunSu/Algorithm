#include <iostream>
#include <vector>
#include <string>
#include <limits.h>

using namespace std;

typedef vector<vector<int> > matrix_t;

// M 배열 출력 함수 (실시간으로 업데이트될 때마다)
void printMatrix(const matrix_t& M, int n, const string& name = "M") {
    // M 배열 출력 (실시간으로 업데이트될 때마다)
    cout << "\n현재 " << name << " 배열:\n";
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (j == 1)
                cout << M[i][j] << " ";
            else if (M[i][j] != 0)
                cout << M[i][j] << " ";
        }
        cout << "\n";
    }
    cout << "\n";
}

// 최소 연산 횟수를 계산하는 함수
int minimum(int i, int j, int& mink, vector<int>& d, matrix_t& M, matrix_t& R, string prefix, bool is_last) {
    int minValue = INT_MAX, value;
    string branch = is_last ? "└── " : "├── ";

    // 재귀적으로 각 분할 지점(k)에 대한 비용 계산
    for (int k = i; k <= j - 1; k++) {
        value = M[i][k] + M[k + 1][j] + d[i - 1] * d[k] * d[j];

        // 계산식 출력
        cout << prefix + branch
             << "i = " << i << ", j = " << j << ", k = " << k
             << ", cost = M[" << i << "][" << k << "] + M[" << k + 1 << "][" << j << "] + "
             << d[i - 1] << " * " << d[k] << " * " << d[j] << " = "
             << M[i][k] << " + " << M[k + 1][j] << " + "
             << d[i - 1] * d[k] * d[j] << " = "
             << value << endl;

        if (minValue > value) {
            minValue = value;
            mink = k;
        }
    }

    return minValue;
}

// 행렬 곱셈 최소 비용 계산 함수
void minmult(int n, vector<int>& d, matrix_t& M, matrix_t& R, string prefix = "", bool is_last = true) {
    for (int i = 1; i <= n; i++) {
        M[i][i] = 0;  // 단일 행렬은 곱셈이 필요 없으므로 0으로 초기화
    }

    // 대각선 크기에 따른 반복문
    for (int diagonal = 1; diagonal <= n - 1; diagonal++) {
        cout << "\n현재 diagonal: " << diagonal << endl;

        for (int i = 1; i <= n - diagonal; i++) {
            int j = i + diagonal;  // j는 현재 대각선 크기에 해당하는 j
            int k;
            string branch = is_last ? "└── " : "├── ";

            cout << prefix + branch << "Calculating M[" << i << "][" << j << "]\n";

            // 최소 비용 계산
            M[i][j] = minimum(i, j, k, d, M, R, prefix + (is_last ? "    " : "│   "), false);
            R[i][j] = k;  // 분할 지점 기록

            // 출력된 재귀적 트리 구조
            cout << prefix + (is_last ? "    " : "│   ") << "M[" << i << "][" << j << "] = " << M[i][j] << " (split at k = " << k << ")\n";
            
            // M 배열을 업데이트할 때마다 실시간으로 출력
            printMatrix(M, n, "M");

            // R 배열도 업데이트 될 때마다 실시간으로 출력
            printMatrix(R, n, "R");
        }
    }
}

// 최적 곱셈 순서를 출력하는 함수 (트리 구조)
void order(int i, int j, matrix_t& R, string& s, string prefix = "", bool is_last = true) {
    string branch = is_last ? "└── " : "├── ";

    // 시각적으로 업데이트된 변수 추적
    cout << prefix + branch << "i = " << i << ", j = " << j << ", R[" << i << "][" << j << "] = " << R[i][j] << endl;

    if (i == j) {
        s += prefix + branch + "A" + to_string(i) + "\n";  // 단일 행렬은 A[i]
    } else {
        int k = R[i][j]; // 최적 분할 지점 k 추적
        s += prefix + branch + "(\n";
        order(i, k, R, s, prefix + (is_last ? "    " : "│   "), false); // 왼쪽 서브문제
        order(k + 1, j, R, s, prefix + (is_last ? "    " : "│   "), true);  // 오른쪽 서브문제
        s += prefix + (is_last ? "    " : "│   ") + ")\n";
    }
}

int main() {
    // 목표: 행렬 곱셈의 최적화된 순서를 구하고, 최소 연산 횟수를 계산하는 프로그램
    cout << "목표: 주어진 행렬 차원 배열에 대해 최소 곱셈 횟수를 계산하고, 최적 곱셈 순서를 구하는 프로그램입니다.\n\n";

    // 행렬 크기 입력
    int n;
    cout << "행렬 크기: ";
    cin >> n;

    // 행렬 크기에 맞는 차원 배열 입력
    vector<int> d(n + 1);
    cout << "행렬 차원 배열 (크기 " << n << "): ";
    for (int i = 0; i <= n; i++) {
        cin >> d[i];
    }

    // d배열 출력
    cout << "\n차원 배열 (d): ";
    for (int i = 0; i <= n; i++) {
        cout << d[i] << " ";
    }
    cout << "\n\n";

    matrix_t M(n + 1, vector<int>(n + 1, 0));  // 곱셈 결과 테이블
    matrix_t R(n + 1, vector<int>(n + 1, 0));  // 분할 지점 테이블

    // 연쇄 행렬 곱셈 공식 출력
    cout << "\n연쇄 행렬 곱셈 공식: M[i][j] = min(M[i][k] + M[k+1][j] + d[i-1] * d[k] * d[j])\n";
    
    // 기본 값과 점화식 출력
    cout << "\n기본 값: M[i][i] = 0 (하나의 행렬은 곱셈이 불필요)\n";
    cout << "점화식: M[i][j] = min(M[i][k] + M[k+1][j] + d[i-1] * d[k] * d[j]) for all k in [i, j-1]\n\n";

    // 행렬 곱셈 최소 비용 계산 시작
    minmult(n, d, M, R);

    // 최적 곱셈 횟수 출력
    cout << "\n최소 곱셈 횟수: " << M[1][n] << endl;

    // 최적 곱셈 순서 출력 (트리 형태)
    string optimal_order;
    order(1, n, R, optimal_order);
    cout << "\n최적 곱셈 순서 (트리 구조):\n" << optimal_order;

    return 0;
}
