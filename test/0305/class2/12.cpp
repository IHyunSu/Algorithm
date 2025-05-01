#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int main() 
{
    int n;
    cin >> n;
    if (n == 0) 
    {
        cout << 0 << endl;
        return 0;
    }
    vector<int> arr(n);
    
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    
    sort(arr.begin(), arr.end());

    int cut = round(n * 0.15);
    int sum = 0;
    
    for (int i = cut; i < n - cut; i++) 
        sum += arr[i];
    
    double avg = static_cast<double>(sum) / (n - 2 * cut);
    cout << round(avg) << endl;
}
