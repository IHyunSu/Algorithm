// 10773

#include <iostream>
#include <stack>
#include <vector>
using namespace std;

/**
 * 1. 재민이에게 숫자를 입력받으면 스택에 push한다.
 * 2. 재민이가 잘못된 수인 0을 입력했다면 최근의 수를 pop한다.
 * 3. 결론적으로 스택에 남은 숫자들의 합을 출력한다.
 */

// push, pop

int main () {
    int k, num;
    cin >> k;
    vector<int> arr(k);

    for (int i = 0; i < k; i++) {
        cin >> num;
        if (num != 0) {
            arr.push_back(num);
        } else if (!arr.empty()) {
            arr.pop_back();
        }
    }
    
    int sum = 0;
    for (int val : arr) {
        sum += val;
    }

    cout << sum << endl;
}