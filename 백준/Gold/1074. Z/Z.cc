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

        int quadrant = 0;
        if (r >= half) 
        { 
            quadrant += 2;
            r -= half; 
        }

        if (c >= half) 
        { 
            quadrant += 1;
            c -= half; 
        }

        answer += size * quadrant;
        --n;
    }

    cout << answer;
}