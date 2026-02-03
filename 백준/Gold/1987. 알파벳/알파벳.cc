#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

int r, c;

string board[20];
bool visited[26] = { false };

// 상, 좌, 하, 우
int dy[4] = { -1, 0, 1, 0 };
int dx[4] = { 0, -1, 0, 1 };

int solve(int toPick, int y, int x)
{
    int answer = toPick;
    for (int d = 0; d < 4; ++d)
    {
        int ny = y + dy[d];
        int nx = x + dx[d];
        if (ny < 0 || nx < 0 || ny >= r || nx >= c)
            continue;

        int idx = board[ny][nx] - 'A';
        if (visited[idx])
            continue;

        visited[idx] = true;
        answer = max(answer, solve(toPick + 1, ny, nx));
        visited[idx] = false;
    }

    return answer;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> r >> c;
    for (int i = 0; i < r; ++i)
        cin >> board[i];

    visited[board[0][0] - 'A'] = true;
    cout << solve(1, 0, 0);
    return 0;
}