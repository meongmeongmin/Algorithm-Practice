#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int solve(int n, int r, int c)
{
    if (n == 0)
        return 0;
    return 2 * (r % 2) + (c % 2) + 4 * solve(n - 1, r / 2, c / 2);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, r, c;
    cin >> n >> r >> c;
    cout << solve(n, r, c);
}