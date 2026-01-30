#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    
    struct people
    {
        long long w, s; // 몸무게, 버틸 힘
    };

    vector<people> peoples(n);
    for (int i = 0; i < n; ++i)
    {
        int w, s;
        cin >> peoples[i].w >> peoples[i].s;
    }

    sort(peoples.begin(), peoples.end(),
        [](people& p1, people& p2) {
            return p1.w + p1.s < p2.w + p2.s;
        });
    
    long long wSum = 0;
    long long answer = INT_MIN;
    for (const people& p : peoples)
    {
        answer = max(answer, wSum - p.s);  // 최대 위험도
        wSum += p.w;
    }
    
    cout << answer;
    return 0;
}