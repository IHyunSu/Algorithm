#include <iostream>
using namespace std;
string A, B, C;
int main()
{
    cin >> A >> B >> C;
    cout << stoi(A) + stoi(B) - stoi(C) << "\n";
    cout << stoi(A + B) - stoi(C);
    return 0;
}