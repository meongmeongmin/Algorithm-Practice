#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, r, c;
    cin >> n >> r >> c;

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