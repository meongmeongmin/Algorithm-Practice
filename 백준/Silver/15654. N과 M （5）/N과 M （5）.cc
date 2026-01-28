#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n;
int m;  // 수열 길이

vector<int> nums;
vector<int> answers;
vector<bool> visited;

void solve(int toPick)
{
    if (toPick == m)
    {
        for (const int& n : answers)
            cout << n << ' ';
        
        cout << '\n';
        return;
    }
    
    for (int i = 0; i < n; ++i)
    {
        if (visited[i])
            continue;

        visited[i] = true;

        answers.emplace_back(nums[i]);
        solve(toPick + 1);
        answers.pop_back();

        visited[i] = false;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;
    nums.resize(n);
    visited.resize(n, false);

    vector<vector<int>> v(2, vector<int>(n));
    for (int i = 0; i < n; ++i)
        cin >> nums[i];

    sort(nums.begin(), nums.end());

    if (m == 1)
    {
        for (const int& a : nums)
            cout << a << '\n';
        
        return 0;
    }

    solve(0);
    //sort(seq.begin(), seq.end());

    return 0;
}