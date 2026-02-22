#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <climits>

using namespace std;

int N;
int R;
int board[20][20];
int answer = INT_MAX;

bool start[20];

void solve(int idx, int count)
{
    if (count == R)
    {
        int startSum = 0;
        int linkSum = 0;

        for (int i = 0; i < N; i++)
        {
            for (int j = i + 1; j < N; j++)
            {
                if (start[i] && start[j])
                    startSum += board[i][j] + board[j][i];
                else if (!start[i] && !start[j])
                    linkSum += board[i][j] + board[j][i];
            }
        }

        answer = min(answer, abs(startSum - linkSum));
        if (answer == 0)
        {
            cout << 0;
            exit(0);
        }

        return;
    }

    for (int i = idx; i < N; ++i)
    {
        if (start[i])
            continue;

        start[i] = true;
        solve(i + 1, count + 1);
        start[i] = false;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    R = N / 2;

    for (int r = 0; r < N; ++r)
        for (int c = 0; c < N; ++c)
            cin >> board[r][c];
    
    solve(0, 0);
    cout << answer;
}