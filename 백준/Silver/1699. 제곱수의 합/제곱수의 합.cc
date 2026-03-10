#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;
    vector<int> dp(n + 1);
    dp[0] = 0;
    
    for (int now = 1; now <= n; ++now)
    {
        dp[now] = now;
        int num = 1;

        for (int next = 1; ; ++next)
        {
            num = next * next;
            if (num > now)
                break;
            dp[now] = min(dp[now], dp[now - num] + 1);
        }
    }

    cout << dp[n];
}