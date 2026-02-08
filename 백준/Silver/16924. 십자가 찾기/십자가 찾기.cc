#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <climits>

using namespace std;

int n, m;   // 행, 열
char board[100][100];
bool covered[100][100] = { false };

// 상좌하우
int dy[4] = { -1, 0, 1, 0 };
int dx[4] = { 0, -1, 0, 1 };

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
            cin >> board[r][c];

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
                int minSize = INT_MAX;
                for (int dir = 0; dir < 4; ++dir)
                    minSize = min(minSize, findSize(dir, r, c));

                for (int s = minSize; s > 0; --s)
                {
                    xx.push_back(r + 1);
                    yy.push_back(c + 1);
                    ss.push_back(s);
                }
            }
        }

    int size = xx.size();
    if (size == 0)
    {
        cout << -1;
        return 0;
    }

    for (int i = 0; i < size; ++i)
    {
        int r = xx[i] - 1;
        int c = yy[i] - 1;
        int s = ss[i];

        covered[r][c] = true;

        for (int dir = 0; dir < 4; ++dir)
        {
            int nr = r;
            int nc = c;

            for (int k = 0; k < s; ++k)
            {
                nr += dy[dir];
                nc += dx[dir];
                covered[nr][nc] = true;
            }
        }
    }
    
    for (int r = 0; r < n; ++r)
        for (int c = 0; c < m; ++c)
            if (board[r][c] == '*' && covered[r][c] == false)
            {
                cout << -1;
                return 0;
            }

    cout << size << '\n';
    for (int i = 0; i < size; ++i)
        cout << xx[i] << ' ' << yy[i] << ' ' << ss[i] << '\n';
}