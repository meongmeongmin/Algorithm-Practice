#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    #pragma region I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    #pragma endregion

    int n;
    cin >> n;
    int LeavingDay = n + 1; // 퇴사 날

    vector<int> t(n);   // 상담을 완료하는데 걸리는 기간
    vector<int> p(n);   // 상담을 했을 때 받을 수 있는 금액
    for (int i = 0; i < n; i++)
        cin >> t[i] >> p[i];

    vector<int> dp(LeavingDay);
    for (int day = n; day > 0; day--)
    {
        int idx = day - 1;  // 현재 인덱스
        int nextDay = day + t[idx]; // 다음 상담 날

        if (nextDay <= LeavingDay)
        {
            int nextIdx = nextDay - 1;  // 다음 상담 날 인덱스
            dp[idx] = max(p[idx] + dp[nextIdx], dp[idx + 1]);
        }
        else
            dp[idx] = dp[idx + 1];
    }

    cout << dp[0];
}