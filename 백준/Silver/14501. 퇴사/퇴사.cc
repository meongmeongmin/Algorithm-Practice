#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    const int MAX = 15;

    int n;
    cin >> n;
    pair<int, int> arr[MAX];
    for (int i = 0; i < n; ++i)
        cin >> arr[i].first >> arr[i].second;

    int dp[MAX] = { 0 };
    for (int i = n - 1; i >= 0; --i)
    {
        int next = i + arr[i].first;
        dp[i] = next > n ? dp[i + 1] : max(arr[i].second + dp[next], dp[i + 1]);
    }

    cout << dp[0];
}