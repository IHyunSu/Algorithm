    // 2231
    #include <iostream>
    using namespace std;

    int main () {
        int N;
        cin >> N;
        int result = 0;

        for (int i = 1; i < N; i++) 
        {
            int sum = 0;
            sum += i;
            int temp = i;
            while (temp != 0) 
            {
                sum += temp % 10;
                temp /= 10;
            }
            if (sum == N)
            {
                result = i;
                break;
            }
        }

        cout << result;
    }