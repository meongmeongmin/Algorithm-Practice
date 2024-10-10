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

    vector<int> dayMaxProfit(n);    // 해당 날짜부터 상담을 시작하면 얻는 최대 수익
    for (int i = 0; i < n; i++)
    {
        int day = n - i;   // 현재
        int idx = day - 1;  // 현재 인덱스
        
        int nextDay = day + t[idx]; // 다음 상담 날

        if (nextDay > LeavingDay)
        {
            dayMaxProfit[idx] = 0; // 상담 불가능
            continue;
        }

        dayMaxProfit[idx] = p[idx];
        
        int maxProfit = 0;
        for (int nextIdx = nextDay - 1; nextIdx < n; nextIdx++)
        {
            if (dayMaxProfit[nextIdx] != 0 && maxProfit < dayMaxProfit[nextIdx])
                maxProfit = dayMaxProfit[nextIdx];
        }

        dayMaxProfit[idx] += maxProfit;
    }

    cout << *max_element(dayMaxProfit.begin(), dayMaxProfit.end());
}