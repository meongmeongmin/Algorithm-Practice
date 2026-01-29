#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int l;  // 길이
int c;  // 문자 갯수

vector<char> ch;
string answers;

void solve(int toPick, int idx)
{
    if (toPick == l)
    {
        int vowelCount = 0;
        for (const char& c : answers)
            if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u')
                vowelCount++;

        // 최소 한 개의 모음과 최소 두 개의 자음
        if (vowelCount >= 1 && (l - vowelCount) >= 2)
            cout << answers << '\n';
        
        return;
    }

    for (int i = idx; i < c; ++i)
    {
        answers += ch[i];
        solve(toPick + 1, i + 1);
        answers.pop_back();
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> l >> c;
    ch.resize(c);

    for (int i = 0; i < c; ++i)
        cin >> ch[i];

    sort(ch.begin(), ch.end());
    solve(0, 0);

    return 0;
}