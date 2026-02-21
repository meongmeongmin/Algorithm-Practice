#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;

    int lEight = 0;
    int rEight = 0;
    int Huri = 0;
    int lLeg = 0;
    int rLeg = 0;

    pair<int, int> heart = { -1, -1 };  // r, c

    vector<vector<char>> board(N, vector<char>(N));
    for (int r = 0; r < N; ++r)
        for (int c = 0; c < N; ++c)
        {
            cin >> board[r][c];
            if (heart.first == -1 && board[r][c] == '*')
            {
                heart.first = r + 1;
                heart.second = c;
            }
        }

    cout << heart.first + 1 << ' ' << heart.second + 1 << '\n';

    // 왼쪽 팔
    for (int c = heart.second - 1; c >= 0; --c)
    {
        if (board[heart.first][c] != '*')
            break;
        ++lEight;
    }

    cout << lEight << ' ';

    // 오른쪽 팔
    for (int c = heart.second + 1; c < N; ++c)
    {
        if (board[heart.first][c] != '*')
            break;
        ++rEight;
    }

    cout << rEight << ' ';

    // 허리
    for (int r = heart.first + 1; r < N; ++r)
    {
        if (board[r][heart.second] != '*')
            break;
        ++Huri;
    }

    cout << Huri << ' ';

    // 왼쪽 다리
    int cc = heart.second - 1;
    for (int r = heart.first + Huri + 1; r < N; ++r)
    {
        if (board[r][cc] != '*')
            break;
        ++lLeg;
    }

    cout << lLeg << ' ';

    // 오른쪽 다리
    cc += 2;
    for (int r = heart.first + Huri + 1; r < N; ++r)
    {
        if (board[r][cc] != '*')
            break;
        ++rLeg;
    }

    cout << rLeg;
}