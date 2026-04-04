#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n;
    cin >> n;
    vector<pair<int, int>> pos(n);
    for (int i = 0; i < n; i++)
        cin >> pos[i].first >> pos[i].second;
    sort(pos.begin(), pos.end());
    for (const pair<int, int>& xy : pos)
        cout << xy.first << ' ' << xy.second << '\n';
}