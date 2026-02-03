#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

const int SIZE = 10;

bool board[SIZE][SIZE];
int paper[5] = { 5, 5, 5, 5, 5};    // 색종이 갯수
int countOnes = 0;  // 남은 갯수

int answer = INT_MAX;

bool canPaste(int len, int y, int x)
{
    if (paper[len - 1] <= 0) 
        return false;
    
    if (y + len > SIZE || x + len > SIZE)
        return false;

    for (int r = y; r < y + len; ++r)
        for (int c = x; c < x + len; ++c)
            if (!board[r][c])
                return false;

    return true;
}

void paste(int len, int y, int x)
{
    for (int r = y; r < y + len; ++r)
        for (int c = x; c < x + len; ++c)
            board[r][c] = false;
}

void unpaste(int len, int y, int x)
{
    for (int r = y; r < y + len; ++r)
        for (int c = x; c < x + len; ++c)
            board[r][c] = true;
}

void solve(int toPick)
{
    if (countOnes == 0)
    {
        answer = min(answer, toPick);
        return;
    }

    int r = -1, c = -1;
    for (int rr = 0; rr < SIZE; ++rr)
    {
        for (int cc = 0; cc < SIZE; ++cc)
            if (board[rr][cc])
            {
                r = rr;
                c = cc;
                break;
            }

        if (r != -1)
            break;
    }

    for (int l = 5; l >= 1; --l)
    {
        if (canPaste(l, r, c))
        {
            paste(l, r, c);
            paper[l - 1]--;
            countOnes -= l * l;

            solve(toPick + 1);

            unpaste(l, r, c);
            paper[l - 1]++;
            countOnes += l * l;
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    for (int r = 0; r < SIZE; ++r)
        for (int c = 0; c < SIZE; ++c)
        {
            cin >> board[r][c];
            if (board[r][c])
                countOnes++;
        }

    solve(0);
    cout << (answer == INT_MAX ? -1 : answer);
    return 0;
}