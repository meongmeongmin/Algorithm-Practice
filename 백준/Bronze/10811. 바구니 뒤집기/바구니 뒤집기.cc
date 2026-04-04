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

    int n, m;
    cin >> n >> m;
    int answer[100];
    for (int i = 1; i <= n; ++i)
        answer[i] = i;

    for (int mm = 0; mm < m; ++mm)
    {
        int i, j;
        cin >> i >> j;
        reverse(answer + i, answer + j + 1);
    }

    for (int i = 1; i <= n; ++i)
        cout << answer[i] << ' ';
}