// Greedy Approach (3) Fibonacci Decomposition

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    unsigned long long N;
    cin >> N;

    // 피보나치 수열 생성 (최대 값이 2^64 - 1 이하)
    vector<unsigned long long> fib = {1, 2}; // 제켄도르프 정리에선 F(1) = 1, F(2) = 2 기준

    while (true)
    {
        unsigned long long next = fib[fib.size() - 1] + fib[fib.size() - 2];
        if (next > N)
            break;
        fib.push_back(next);
    }

    // 그리디하게 큰 수부터 선택
    vector<unsigned long long> result;
    for (int i = fib.size() - 1; i >= 0; --i)
    {
        if (fib[i] <= N)
        {
            result.push_back(fib[i]);
            N -= fib[i];
            // 연속된 피보나치 수를 피하기 위해 바로 이전 항은 skip
            i--; // i-- 한 번 더 해서 건너뜀
        }
    }

    // 오름차순 출력
    sort(result.begin(), result.end());
    for (auto num : result)
        cout << num << '\n';

    return 0;
}
