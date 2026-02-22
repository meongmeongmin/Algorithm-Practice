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

vector<int> start, link;

void solve(int idx, int startSum, int linkSum)
{
    if (idx == N)
    {
        answer = min(answer, abs(startSum - linkSum));
        if (answer == 0)
        {
            cout << 0;
            exit(0);
        }
        return;
    }

    if (start.size() != R)
    {
        int newSum = 0;
        for (const int& oldIdx : start) 
            newSum += board[idx][oldIdx] + board[oldIdx][idx];

        start.push_back(idx);
        solve(idx + 1, startSum + newSum, linkSum);
        start.pop_back();
    }

    if (link.size() != R)
    {
        int newSum = 0;
        for (const int& oldIdx : link)
            newSum += board[idx][oldIdx] + board[oldIdx][idx];
    
        link.push_back(idx);
        solve(idx + 1, startSum, linkSum + newSum);
        link.pop_back();
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
    
    solve(0, 0, 0);
    cout << answer;
}