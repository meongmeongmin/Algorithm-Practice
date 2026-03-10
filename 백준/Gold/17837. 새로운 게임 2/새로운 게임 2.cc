#include <iostream>
#include <tuple>
#include <vector>
#include <algorithm>

using namespace std;

int N, K;

int board[12][12];
tuple<int, int, int> pos[10];   // 말 번호의 위치
vector<int> pieces[12][12]; // 해당 좌표에 쌓인 말

// →, ←, ↑, ↓
int dy[4] = { 0, 0, -1, 1 };
int dx[4] = { 1, -1, 0, 0 };

void move(int piece, int y, int x, int ny, int nx, bool is_red)
{
    int start = 0;
    int size = pieces[y][x].size();

    for (int i = 0; i < size; ++i) 
    {
        if (pieces[y][x][i] == piece) 
        {
            start = i;
            break;
        }
    }

    if (is_red) 
        reverse(pieces[y][x].begin() + start, pieces[y][x].end());

    for (int i = start; i < size; ++i) 
    {
        get<0>(pos[pieces[y][x][i]]) = ny;
        get<1>(pos[pieces[y][x][i]]) = nx;
        pieces[ny][nx].push_back(pieces[y][x][i]);
    }

    pieces[y][x].erase(pieces[y][x].begin() + start, pieces[y][x].end());
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> K;
    for (int r = 0; r < N; ++r)
        for (int c = 0; c < N; ++c)
            cin >> board[r][c];

    for (int i = 0; i < K; ++i)
    {
        int r, c, d;
        cin >> r >> c >> d;
        --r; --c; --d;

        pos[i] = { r, c, d };
        pieces[r][c].push_back(i);
    }

    int answer = 1;
    while (answer <= 1000)
    {
        for (int i = 0; i < K; ++i)
        {
            int y = get<0>(pos[i]);
            int x = get<1>(pos[i]);
            int dir = get<2>(pos[i]);

            int ny = y + dy[dir];
            int nx = x + dx[dir];

            if (ny < 0 || nx < 0 || ny >= N || nx >= N || board[ny][nx] == 2)
            {
                dir % 2 == 0 ? ++dir : --dir;   // 반대
                get<2>(pos[i]) = dir;

                ny = y + dy[dir];
                nx = x + dx[dir];

                if (ny < 0 || nx < 0 || ny >= N || nx >= N || board[ny][nx] == 2)
                    continue;
            }
            
            move(i, y, x, ny, nx, board[ny][nx] == 1);
            if (pieces[ny][nx].size() >= 4)
            {
                cout << answer;
                return 0;
            }
        }

        ++answer;
    }

    cout << -1;
}