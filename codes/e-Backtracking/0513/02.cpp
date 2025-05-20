// Back Tracking : Sum-of-Subsets 

/**
 * 0. 검색하기 전에 정수 원소를 비내림차순으로 정렬한다.
 * 1. weight는 레벨 i까지의 모든 정수 원소의 합이다.
 *  => weigth가 W와 같지 않으면(그 노드에 해답이 있다는 의미)
 *      - weight + w_i+1_ > W 이라면 레벨 i의 노드는 유망하지 않다.
 * 2. total은 남은 정수 원소의 합이다.
 *  => 남은 정수 원소의 합에다 weight를 더해도 최소한 W와 같아지지 않으므로,
 *      - weight + total < W 이라면 이 노드는 유망하지 않다.
 */

// code

// include
#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

// define constant
int N, W;
int cnt = 0;
vector<int> w;
vector<bool> include;
vector<string> buffer;

// utility
int sum(vector<int> arr) {
    int sum = 0;
    for (int var : arr)
        sum += var;
    return sum;
}

// define algorithm functions
void sum_of_subsets (int i, int weight, int total);
bool promising (int i, int weight, int total);

// main function
int main () {
    cin >> N >> W;
    // resize
    w.resize(N + 1, 0);
    include.resize(N + 1, false);

    // input
    for (int i = 1; i <= N; i++)
        cin >> w[i];

    // send functions
    int total = sum(w);
    sum_of_subsets(0, 0, total);

    // print display
    cout << cnt << '\n';
    if (cnt != 0) {
        for (int i = 0; i < buffer.size(); i++)
            cout << buffer[i] << '\n';
    }
}

// define algorithm functions
void sum_of_subsets (int i, int weight, int total)
{
    int n = w.size() - 1;
    if (promising(i, weight, total))
    {
        if (weight == W)
        {
            cnt++;
            // 부분집합 저장
            string subset;
            for (int i = 1; i <= n; i++) {
                if (include[i]) {
                    if (!subset.empty()) subset += " ";
                    subset += to_string(w[i]);
                }
            }
            buffer.push_back(subset);
        }
        else
        {
            include[i + 1] = true;
            sum_of_subsets(i + 1, weight + w[i+1], total - w[i+1]);
            include[i + 1] = false;
            sum_of_subsets(i + 1, weight, total - w[i+1]);
        }
    }
}
bool promising (int i, int weight, int total)
{
    if ((weight + total >= W) &&
        (weight == W || weight + w[i+1] <= W))
        return true;
    else
        return false;
}