#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

long long solve(int a, int b, int c)
{
    if (b == 0)
        return 1;
    else if (b == 1)
        return a % c;

    long half = solve(a, b / 2, c) % c;

    if (b % 2 == 0)
        return (half * half) % c;
    else
        return (half * half % c) * a % c;
}

int main() 
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int a, b, c;
    cin >> a >> b >> c;
    cout << solve(a, b, c);
}