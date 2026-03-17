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
            a[idx].second = n - idx;
            sum += a[idx].first;
        }

        if (sum < p)
        {
            cout << "IMPOSSIBLE\n";
            continue;
        }

        sort(a, a + n);
        int answer[100];
        for (int i = 0; i < n; ++i)
        {
            int idx = n - a[i].second;
            answer[idx] = min(a[i].first, p / (n - i));
            p -= answer[idx];
        }

        for (int i = 0; i < n; ++i)
            cout << answer[i] << ' ';
        cout << '\n';
    }
}