#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N;
bool board[128][128];

int white = 0;
int blue = 0;

void solve(int n, int y, int x)
{
    if (n == 0)
        return;
    
    bool startColor = board[y][x];
    bool same = true;

    int rr = y + n;
    int cc = x + n;
    for (int r = y; r < rr; ++r)
    {
        for (int c = x; c < cc; ++c)
            if (startColor != board[r][c])
            {
                same = false;
                break;
            }

        if (same == false)
            break;
    }
    
    if (same)
    {
        startColor ? ++blue : ++white;
        return;
    }
    
    int half = n / 2;
    solve(n / 2, y, x);
    solve(n / 2, y, x + half);
    solve(n / 2, y + half, x);
    solve(n / 2, y + half, x + half);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    for (int r = 0; r < N; ++r)
        for (int c = 0; c < N; ++c)
            cin >> board[r][c];

    solve(N, 0, 0);
    cout << white << '\n' << blue;
}