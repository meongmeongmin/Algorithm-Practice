#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>

using namespace std;

int n;
int m;  // 수열 길이

vector<int> nums;
vector<int> picked;
unordered_set<int> pickedIdx;

vector<vector<int>> answers;

void solve(int toPick)
{
    if (toPick == m)
    {
        answers.push_back(picked);
        return;
    }
    
    for (int i = 0; i < n; ++i)
    {
        if (pickedIdx.count(i))
            continue;

        pickedIdx.insert(i);

        picked.emplace_back(nums[i]);
        solve(toPick + 1);
        picked.pop_back();

        pickedIdx.erase(i);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;
    nums.resize(n);

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

    for (const vector<int>& v : answers)
    {
        for (const int& n : v)
            cout << n << ' ';
        cout << '\n';
    }

    return 0;
}