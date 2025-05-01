// 11650

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main ()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;

    vector<pair<int, int> > coord(n);
    for (int i = 0; i < n; i++)
    {
        pair<int, int> input;
        cin >> input.first >> input.second;
        coord[i] = input;
    }

    sort(coord.begin(), coord.end());

    for (int i = 0; i < n; i++)
    {
        cout << coord[i].first << " " << coord[i].second << endl;
    }

    return 0;
}