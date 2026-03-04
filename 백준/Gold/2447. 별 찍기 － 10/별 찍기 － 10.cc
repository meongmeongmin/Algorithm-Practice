#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include <string>

using namespace std;

string solve(int n, int y, int x)
{
    if (n == 3)
        return "***\n* *\n***\n";

    string base = solve(n / 3, y, x);
    string result = "";
    string rows = "";

    for (const char& ch : base)
    {
        if (ch == '\n')
        {
            result += rows;
            result += rows;
            result += rows;
            result.push_back('\n');

            rows = "";
            continue;
        }
        
        rows.push_back(ch);
    }

    base = result;
    result += base;
    result += base;

    int range = n / 3;
    for (int r = 0; r < range; ++r)
    {
        int row = range + r;
        int start = row * (n + 1) + range;
        
        for (int c = 0; c < range; ++c)
            result[start + c] = ' ';
    }

    return result;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;
    cout << solve(N, 0, 0);
}