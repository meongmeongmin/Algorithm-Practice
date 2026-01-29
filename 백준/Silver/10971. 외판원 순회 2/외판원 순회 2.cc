#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

int n;

int m[10][10];  // 거리 비용
bool visited[10];

int answer = INT_MAX;

int solve(int now, int toPick, int dist)
{
    if (dist >= answer)
        return answer;

    if (toPick == n)
    {
        if (m[now][0] == 0)   // 막힘
            return INT_MAX;

        return dist + m[now][0];
    }

    for (int next = 0; next < n; ++next)
    {
        if (visited[next] || m[now][next] == 0)
            continue;

        visited[next] = true;
        answer = min(answer, solve(next, toPick + 1, dist + m[now][next]));
        visited[next] = false;
    }

    return answer;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;

    for (int r = 0; r < n; ++r)
        for (int c = 0; c < n; ++c)
            cin >> m[r][c];

    visited[0] = true;
    cout << solve(0, 1, 0);
    return 0;
}