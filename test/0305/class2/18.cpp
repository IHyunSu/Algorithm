// 2609

#include <iostream>
#include <algorithm>
using namespace std;

int main ()
{
    int a, b;
    cin >> a >> b;

    for (int i = 1; i <= max(a,b); i++) 
    {
        for (int j = 1; j <= max(a,b); j++)
        {
            int result = i * j;
            if (result == max(a,b))
            {
                if (result == min(a,b))
                {
                    cout << result << endl;
                    break;
                }
            }
        }
    }
}