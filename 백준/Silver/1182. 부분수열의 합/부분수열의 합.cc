#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
#include <tuple>

using namespace std;

int n;
int s;

vector<int> nums;

int solve(int idx, int sum)
{
    if (idx == n)
        return (sum == s) ? 1 : 0;

    int count = 0;
    count += solve(idx + 1, sum + nums[idx]);   // 선택 O
    count += solve(idx + 1, sum);   // 선택 X

    return count;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> s;
    
    nums.resize(n);
    for (int i = 0; i < n; ++i)
        cin >> nums[i];

    cout << ((s == 0) ? solve(0, 0) - 1: solve(0, 0));
    return 0;
}