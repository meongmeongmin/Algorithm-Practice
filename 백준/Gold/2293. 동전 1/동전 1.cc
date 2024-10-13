#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n, k;
    cin >> n >> k;

    vector<int> coins(n);
    for (int i = 0; i < n; i++)
        cin >> coins[i];

    vector<int> dp(k);  // coins로 1부터 k까지의 정수를 만들 수 있는 경우의 수
    for (int i = 1; i <= k; i++)
    {
        int idx = i - 1;
        if (i % coins[0] == 0)  // coins[0]만으로 i를 만드는 경우의 수 찾기
            dp[idx]++;
    }

    for (int i = 1; i < n; i++)   // coins[1]부터 dp 구하기
    {
        int idx = coins[i] - 1;
        dp[idx]++;

        for (int nextIdx = idx + 1; nextIdx < k; nextIdx++)
            dp[nextIdx] += dp[nextIdx - coins[i]];
    }

    cout << dp[k - 1];
}
