#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int T;
    cin >> T;

    for (int i = 0; i < T; ++i)
    {
        int p, n;
        cin >> p >> n;

        pair<int, int> a[100];  // 금액, 인덱스
        int sum = 0;

        for (int idx = 0; idx < n; ++idx)
        {
            cin >> a[idx].first;
            a[idx].second = idx;
            sum += a[idx].first;
        }

        if (sum < p)
        {
            cout << "IMPOSSIBLE\n";
            continue;
        }

        sort(a, a + n, [](const pair<int, int>& a, const pair<int, int>& b) {
            if (a.first == b.first)
                return a.second > b.second;
            return a.first < b.first;
        });

        int answer[100];
        for (int i = 0; i < n; ++i)
        {
            int num = n - i;
            int average = p / num;

            if (a[i].first <= average)
            {
                answer[a[i].second] = a[i].first;
                p -= a[i].first;
                continue;
            }

            int r = (p % num > num) ? r % num : 0;
            answer[a[i].second] = r + average;
            p -= answer[a[i].second];
        }

        for (int i = 0; i < n; ++i)
            cout << answer[i] << ' ';
        cout << '\n';
    }
}