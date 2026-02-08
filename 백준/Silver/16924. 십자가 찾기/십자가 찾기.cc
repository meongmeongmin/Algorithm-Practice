#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <climits>

using namespace std;

int n, m;   // 행, 열
char board[100][100];
bool findCross[100][100];

int findCount = 0;

// 상좌하우
int dy[4] = { -1, 0, 1, 0 };
int dx[4] = { 0, -1, 0, 1 };

void updateFindCross(int r, int c, int size)
{
    if (findCross[r][c] == false)
    {
        findCross[r][c] = true;
        --findCount;
    }

    for (int dir = 0; dir < 4; ++dir)
    {
        int nr = r;
        int nc = c;

        for (int i = 0; i < size; ++i)
        {
            nr += dy[dir];
            nc += dx[dir];

            if (findCross[nr][nc] == false)
            {
                findCross[nr][nc] = true;
                --findCount;
            }
        }
    }
}

int findSize(int dir, int nr, int nc)
{
    int ns = 0;
    while (true)
    {
        nr += dy[dir];
        nc += dx[dir];
        if (nr < 0 || nc < 0 || nr >= n || nc >= m || board[nr][nc] != '*')
            break;
        ++ns;
    }

    return ns;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;

    for (int r = 0; r < n; ++r)
        for (int c = 0; c < m; ++c)
        {
            cin >> board[r][c];
            if (board[r][c] == '*')
            {
                findCross[r][c] = false;
                ++findCount;
            }
            else
                findCross[r][c] = true;
        }

    vector<int> xx;
    vector<int> yy;
    vector<int> ss;

    int rr = n - 1;
    int cc = m - 1;
    for (int r = 1; r < rr; ++r)
        for (int c = 1; c < cc; ++c)
        {
            if (board[r][c] != '*')
                continue;

            // 가운데 찾기
            bool find = true;
            for (int dir = 0; dir < 4; ++dir)
            {
                int nr = r + dy[dir];
                int nc = c + dx[dir];
                if (nr < 0 || nc < 0 || nr >= n || nc >= m || board[nr][nc] != '*')
                {
                    find = false;
                    break;
                }
            }

            // 가운데의 길이 찾기
            if (find)
            {
                int min = INT_MAX;
                for (int dir = 0; dir < 4; ++dir)
                {
                    int size = findSize(dir, r, c);
                    if (min > size)
                        min = size;
                }

                int x = r + 1;
                int y = c + 1;
                for (int s = min; s > 0; --s)
                {
                    xx.push_back(x);
                    yy.push_back(y);
                    ss.push_back(s);
                }

                updateFindCross(r, c, min);
            }
        }

    if (findCount != 0)
    {
        cout << -1;
        return 0;
    }

    int size = xx.size();
    if (size == 0)
    {
        cout << -1;
        return 0;
    }

    cout << size << '\n';
    for (int i = 0; i < size; ++i)
        cout << xx[i] << ' ' << yy[i] << ' ' << ss[i] << '\n';
}