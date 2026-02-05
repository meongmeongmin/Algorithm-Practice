#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string l, r;
    cin >> l >> r;

    int len = l.length();
    int answer = 0;

    if (len != r.length())
    {
        cout << answer;
        return 0;
    }

    for (int i = 0; i < len; ++i)
    {
        if (l[i] != r[i])
            break;

        if (l[i] == '8')
            answer++;
    }

    cout << answer;
    return 0;
}