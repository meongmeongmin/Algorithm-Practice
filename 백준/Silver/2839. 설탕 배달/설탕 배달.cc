#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include <cstring>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;

    int dp[5000 + 1];
    memset(dp, -1, (n + 1) * sizeof(int));
    dp[0] = 1;

    for (int now = 3; now <= n; ++now)
    {
        dp[now] = now;
        if (now % 5 == 0)
            dp[now] = now / 5;
        else if (now % 3 == 0)
            dp[now] = now / 3;

        if (dp[now] == 1)
            continue;

        if (now >= 5 && dp[now - 5] != -1)
            dp[now] = min(dp[now], dp[now - 5] + 1);
        if (now >= 3 && dp[now - 3] != -1)
            dp[now] = min(dp[now], dp[now - 3] + 1);

        if (dp[now] == now)
            dp[now] = -1;
    }

    cout << dp[n];
}