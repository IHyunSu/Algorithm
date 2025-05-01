//1259

#include <iostream>
#include <algorithm>
#include <vector>
#include <stdio.h>
using namespace std;

int main ()
{
    string number;
    while (1) 
    {
        cin >> number;
        if (number == "0")
        {
            break;
        }
        string temp = number;
        reverse(number.begin(), number.end());
        if (number == temp)
        {
            cout << "yes" << endl;
        }
        else
        {
            cout << "no" << endl;
        }
    }
}