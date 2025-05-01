// 10814

#include <iostream>
#include <vector>
#include <string.h>
#include <algorithm>
#include <stdio.h>
using namespace std;

bool compare(const pair<int, string>& a, const pair<int, string>& b)
{
    return a.first < b.first;
}

int main ()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    vector<pair<int, string> > users(n);

    for (int i = 0; i < n; i++)
    {
        pair<int, string> input;
        cin >> input.first >> input.second;
        users[i] = input;
    }

    stable_sort(users.begin(), users.end(), compare);

    for (int i = 0; i < n; i++)
    {
        cout << users[i].first << " " << users[i].second << "\n";
    }
}