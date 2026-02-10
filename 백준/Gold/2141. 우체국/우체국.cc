#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    vector<pair<long long, long long>> arr(n);   // 마을, 사람
    long long people = 0;   // 사람 수 총합
    
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i].first >> arr[i].second;
        people += arr[i].second;
    }

    sort(arr.begin(), arr.end());

    long long mid = (people + 1) / 2; // 사람 수가 홀수일 때를 대비하여 1을 더한다
    long long sum = 0;
    
    for (const pair<long long, long long>& a : arr)
    {
        sum += a.second;
        if (sum >= mid)
        {
            cout << a.first;
            return 0;
        }
    }
}