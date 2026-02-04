#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

const int SIZE = 9;

int n;

int board[SIZE][SIZE];
bool visited[SIZE][SIZE + 1] = { false };
int findCount = 0;

// 하, 우
int dy[2] = { 1, 0 };
int dx[2] = { 0, 1 };

void solve()
{
    if (findCount == SIZE * SIZE)
    {
        for (int r = 0; r < SIZE; ++r)
        {
            for (int c = 0; c < SIZE; ++c)
                cout << board[r][c];
            cout << '\n';
        }

        return;
    }

    // 비어 있는 가장 빠른 칸
    int y = -1, x = -1;
    for (int i = 0; i < SIZE; ++i)
    {
        for (int j = 0; j < SIZE; ++j)
            if (board[i][j] == 0)
            {
                y = i;
                x = j;
                break;
            }

        if (y != -1)
            break;
    }

    for (int dir = 0; dir < 2; ++dir)
    {
        int ny = y + dy[dir];
        int nx = x + dx[dir];

        if (ny < 0 || nx < 0 || ny >= SIZE || nx >= SIZE)
            continue;

        if (board[ny][nx] != 0)
            continue;

        int startY = (y / 3) * 3;
        int startX = (x / 3) * 3;

        int startNy = (ny / 3) * 3;
        int startNx = (nx / 3) * 3;

        bool existed[SIZE + 1] = { false };
        for (int r = 0; r < 3; ++r)
        {
            for (int c = 0; c < 3; ++c)
            {
                int num = board[startY + r][startX + c];
                existed[num] = true;
            }
        }

        bool existed2[SIZE + 1] = { false };
        if (startY == startNy && startX == startNx)
        {
            copy(existed, existed + SIZE + 1, existed2);
        }
        else
        {
            for (int r = 0; r < 3; ++r)
            {
                for (int c = 0; c < 3; ++c)
                {
                    int num = board[startNy + r][startNx + c];
                    existed2[num] = true;
                }
            }
        }

        bool numExisted[SIZE + 1] = { false };  // U
        for (int nc = 0; nc < SIZE; ++nc)
        {
            int num = board[y][nc];
            numExisted[num] = true;
        }
        for (int nr = 0; nr < SIZE; ++nr)
        {
            int num = board[nr][x];
            numExisted[num] = true;
        }

        bool nextNumExisted[SIZE + 1] = { false };  // V
        for (int nc = 0; nc < SIZE; ++nc)
        {
            int num = board[ny][nc];
            nextNumExisted[num] = true;
        }
        for (int nr = 0; nr < SIZE; ++nr)
        {
            int num = board[nr][nx];
            nextNumExisted[num] = true;
        }

        // 번호 탐색
        for (int num = 1; num <= SIZE; ++num)
        {
            if (existed[num] || numExisted[num])
                continue;

            for (int nextNum = 1; nextNum <= SIZE; ++nextNum)
            {
                if (existed2[nextNum])
                    continue;

                int d, d1;
                if (num < nextNum)
                {
                    d = num;
                    d1 = nextNum;
                }
                else
                {
                    d = nextNum;
                    d1 = num;
                }

                if (visited[d][d1])
                    continue;

                if (nextNum != num && nextNumExisted[nextNum] == false)
                {
                    board[y][x] = num;
                    board[ny][nx] = nextNum;
                    visited[d][d1] = true;
                    findCount += 2;

                    solve();

                    if (findCount == SIZE * SIZE)
                        return;

                    board[y][x] = 0;
                    board[ny][nx] = 0;
                    visited[d][d1] = false;
                    findCount -= 2;
                }
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int count = 1;
    while (true)
    {
        cin >> n;
        if (n == 0)
            break;

        fill(&board[0][0], &board[0][0] + SIZE * SIZE, 0);
        fill(&visited[0][0], &visited[0][0] + SIZE * (SIZE + 1), false);

        findCount = n * 2 + SIZE;
        string pos; // y, x

        for (int i = 0; i < n; ++i)
        {
            int num, num2;
            cin >> num >> pos;
            board[pos[0] - 'A'][pos[1] - '1'] = num;
            cin >> num2 >> pos;
            board[pos[0] - 'A'][pos[1] - '1'] = num2;

            if (num < num2)
                visited[num][num2] = true;
            else
                visited[num2][num] = true;
        }

        for (int num = 1; num <= SIZE; ++num)
        {
            cin >> pos;
            board[pos[0] - 'A'][pos[1] - '1'] = num;
        }

        cout << "Puzzle " << count++ << '\n';
        solve();
    }

    return 0;
}