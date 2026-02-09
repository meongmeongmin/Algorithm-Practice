#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int n;
int arrSize;
int base[2][2] = { {0, 1}, {2, 3} };

vector<vector<int>> board;
int answer = 0;

void solve(int size)
{
    if (size == 4)
    {

        return;
    }

    solve(size / 2);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int r, c;
    cin >> n >> r >> c;

    board.resize(arrSize, vector<int>(arrSize, -1));
    
    int answer = 0;
    while (n > 0)
    {
        int half = 1 << n - 1;
        int size = half * half;

        if (r < half && c < half)
        {
            // 안 더한다
        }
        else if (r < half && c >= half)
        {
            answer += size * 1;
            c -= half;
        }
        else if (r >= half && c < half)
        {
            answer += size * 2;
            r -= half;
        }
        else
        {
            answer += size * 3;
            r -= half;
            c -= half;
        }

        --n;
    }

    cout << answer;
}