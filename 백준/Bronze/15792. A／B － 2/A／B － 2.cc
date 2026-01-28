#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long l, c;
    cin >> l >> c;
    cout << l / c;

    long long remainder = l % c;
    if (remainder == 0) 
        return 0;

    cout << '.';

    for (int i = 0; i < 1000; i++) 
    {
        remainder *= 10;
        cout << remainder / c;
        remainder %= c;

        if (remainder == 0)
            break;
    }

    return 0;
}