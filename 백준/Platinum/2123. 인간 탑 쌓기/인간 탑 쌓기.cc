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
        int w;
        int s;
    };

    vector<people> peoples(n);
    for (int i = 0; i < n; ++i)
    {
        int w, s;   // 몸무게, 버틸 힘
        cin >> w >> s;
        peoples[i].w = w;
        peoples[i].s = s;
    }

    sort(peoples.begin(), peoples.end(),
        [](people& p1, people& p2) {
            return p1.w + p1.s < p2.w + p2.s;
        });
    
    int wSum = 0;
    int answer = INT_MIN;
   
    for (int i = 0; i < n; ++i)
    {
        answer = max(answer, wSum - peoples[i].s);  // 최대 위험도
        wSum += peoples[i].w;
    }
    
    cout << answer;
    return 0;
}