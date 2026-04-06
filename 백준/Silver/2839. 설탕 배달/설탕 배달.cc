#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include <cstring>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;
    int r = n % 5;
    if (n == 3)
        cout << 1;
    else if (n < 5 || n == 7)
        cout << -1;
    else if (r == 0)
        cout << n / 5;
    else if (r == 3)
        cout << n / 5 + 1;
    else if (r == 1)
        cout << (n - 6) / 5 + 2;
    else if (r == 4)
        cout << (n - 9) / 5 + 3;
    else
        cout << (n - 12) / 5 + 4;
}