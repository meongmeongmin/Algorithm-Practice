#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int MAX = 64;
char board[MAX][MAX];

string answer;

void solve(int n, int y, int x)
{
    char start = board[y][x];
    int half = n / 2;
    bool find = false;

    for (int r = 0; r < n; ++r)
    {
        for (int c = 0; c < n; ++c)
            if (start != board[y + r][x + c])
            {
                find = true;
                break;
            }

        if (find)
            break;
    }

    if (find == false)  // 모두 똑같다
    {
        answer.push_back(start);
        return;
    }

    answer.push_back('(');
    solve(half, y, x);
    solve(half, y, x + half);
    solve(half, y + half, x);
    solve(half, y + half, x + half);
    answer.push_back(')');
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;
    for (int r = 0; r < n; ++r)
        for (int c = 0; c < n; ++c)
            cin >> board[r][c];

    solve(n, 0, 0);
    cout << answer;
}