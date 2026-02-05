#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

const int MAX = 20;

int n;

int board[MAX][MAX];
int answer = INT_MIN;

// 상 좌 하 우
int dy[4] = { -1, 0, 1, 0 };
int dx[4] = { 0, -1, 0, 1 };

void move(int dir, int y, int x, bool(&visited)[MAX][MAX])
{
    int ny = y, nx = x;
    while (true)
    {
        ny = ny + dy[dir];
        nx = nx + dx[dir];

        if (ny < 0 || nx < 0 || ny >= n || nx >= n)
            break;

        if (board[ny][nx] == 0)
        {
            board[ny][nx] = board[y][x];
            board[y][x] = 0;
            y = ny;
            x = nx;
        }
        else if (!visited[ny][nx] && board[ny][nx] == board[y][x])
        {
            visited[ny][nx] = true;
            board[ny][nx] += board[y][x];
            board[y][x] = 0;
            break;
        }
        else
            break;
    }
}

void moveUp()
{
    bool visited[MAX][MAX] = { false };
    for (int y = 1; y < n; ++y)
        for (int x = 0; x < n; ++x)
        {
            if (board[y][x] == 0)
                continue;
            move(0, y, x, visited);
        }
}

void moveLeft()
{
    bool visited[MAX][MAX] = { false };
    for (int x = 1; x < n; ++x)
        for (int y = 0; y < n; ++y)
        {
            if (board[y][x] == 0)
                continue;
            move(1, y, x, visited);
        }
}

void moveDown()
{
    bool visited[MAX][MAX] = { false };
    for (int y = n - 2; y >= 0; --y)
        for (int x = 0; x < n; ++x)
        {
            if (board[y][x] == 0)
                continue;
            move(2, y, x, visited);
        }
}

void moveRight()
{
    bool visited[MAX][MAX] = { false };
    for (int x = n - 2; x >= 0; --x)
        for (int y = 0; y < n; ++y)
        {
            if (board[y][x] == 0)
                continue;
            move(3, y, x, visited);
        }
}

void solve(int count)
{
    if (count == 5)
    {
        int maxNum = 0;
        for (int y = 0; y < n; ++y)
            for (int x = 0; x < n; ++x)
            {
                if (maxNum < board[y][x])
                    maxNum = board[y][x];
            }

        answer = max(answer, maxNum);
        return;
    }

    for (int dir = 0; dir < 4; ++dir)
    {
        int backupBoard[MAX][MAX];
        copy(&board[0][0], &board[0][0] + MAX * MAX, &backupBoard[0][0]);

        switch (dir)
        {
        case 0:
            moveUp();
            break;
        case 1:
            moveLeft();
            break;
        case 2:
            moveDown();
            break;
        case 3:
            moveRight();
            break;
        }

        solve(count + 1);
        copy(&backupBoard[0][0], &backupBoard[0][0] + MAX * MAX, &board[0][0]);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    for (int y = 0; y < n; ++y)
        for (int x = 0; x < n; ++x)
            cin >> board[y][x];

    solve(0);
    cout << answer;
    return 0;
}