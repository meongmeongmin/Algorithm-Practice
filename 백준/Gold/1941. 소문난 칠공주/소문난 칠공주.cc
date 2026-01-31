#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include <queue>

using namespace std;

const int MAX = 5;

char board[MAX][MAX];

// 상, 좌, 하, 우
int dy[4] = { -1, 0, 1, 0 };
int dx[4] = { 0, 1, 0, -1 };

bool picked[MAX * MAX]; // 현재 7명으로 뽑힌 칸
int answer = 0;

bool isConnected()
{
    bool visited[MAX][MAX] = { false };
    queue<pair<int, int>> q;

    // 선택된 첫 칸 찾기
    for (int i = 0; i < 25; ++i)
    {
        if (picked[i])
        {
            int y = i / MAX;
            int x = i % MAX;

            q.push({ y, x });
            visited[y][x] = true;
            break;
        }
    }

    int count = 1;
    while (q.empty() == false)
    {
        pair<int, int> now = q.front();
        q.pop();

        int y = now.first;
        int x = now.second;

        for (int d = 0; d < 4; ++d)
        {
            int ny = y + dy[d];
            int nx = x + dx[d];

            if (ny < 0 || nx < 0 || ny >= MAX || nx >= MAX)
                continue;

            int idx = ny * MAX + nx;
            if (picked[idx] == false || visited[ny][nx])
                continue;

            visited[ny][nx] = true;
            q.push({ ny, nx });
            count++;
        }
    }

    return count == 7;
}

void solve(int idx, int toPick, int sCount)
{
    if (toPick == 7)
    {
        // 이다솜파가 적어도 4명 이상
        if (sCount >= 4 && isConnected())
            answer++;
        return;
    }

    if (idx == 25)
        return;

    picked[idx] = true;
    solve(idx + 1, toPick + 1, sCount + (board[idx / MAX][idx % MAX] == 'S'));  // 선택 o
    picked[idx] = false;

    solve(idx + 1, toPick, sCount); // 선택 x
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    for (int r = 0; r < MAX; ++r)
        for (int c = 0; c < MAX; ++c)
            cin >> board[r][c];

    solve(0, 0, 0);
    cout << answer;
    return 0;
}