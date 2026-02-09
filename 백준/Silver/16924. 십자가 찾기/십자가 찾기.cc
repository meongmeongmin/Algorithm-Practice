#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

char board[101][101];
bool findCross[100][100];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    // 상좌하우
    int dy[4] = { -1, 0, 1, 0 };
    int dx[4] = { 0, -1, 0, 1 };

    int n, m;   // 행, 열
    cin >> n >> m;
    int findCount = 0;

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

            // 가운데, 길이 찾기
            int size = 0;
            while (true)
            {
                bool find = true;
                for (int dir = 0; dir < 4; dir++)
                {
                    int ny = r + dy[dir] * (size + 1);
                    int nx = c + dx[dir] * (size + 1);
                    if (ny < 0 || nx < 0 || ny >= n || nx >= m || board[ny][nx] != '*')
                    {
                        find = false;
                        break;
                    }
                }
                
                if (!find)
                    break;
                
                size++;
            }

            if (size > 0)
            {
                int x = r + 1;
                int y = c + 1;

                if (findCross[r][c] == false)
                {
                    findCross[r][c] = true;
                    --findCount;
                }

                for (int dir = 0; dir < 4; ++dir)
                {
                    for (int s = size; s > 0; --s)
                    {
                        int ny = r + dy[dir] * (s);
                        int nx = c + dx[dir] * (s);

                        if (findCross[ny][nx] == false)
                        {
                            findCross[ny][nx] = true;
                            --findCount;
                        }

                        if (dir == 0)
                        {
                            xx.emplace_back(x);
                            yy.emplace_back(y);
                            ss.emplace_back(s);
                        }
                    }

                }
            }
        }

    if (findCount != 0)
    {
        cout << -1;
        return 0;
    }

    int size = xx.size();
    cout << size << '\n';
    for (int i = 0; i < size; ++i)
        cout << xx[i] << ' ' << yy[i] << ' ' << ss[i] << '\n';
}