#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    long long n;
    cin >> n;
    
    if (n <= 1)
    {
        cout << n;
        return 0;
    }
    
    long long fn2 = 0;
    long long fn1 = 1;
    for (long long i = 2; i < n; ++i)
    {
        long long tmp = fn1;
        fn1 += fn2;
        fn2 = tmp;
    }

    cout << (fn2 + fn1);
}