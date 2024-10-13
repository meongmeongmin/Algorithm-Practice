#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int main()
{
    #pragma region I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    #pragma endregion

    int n;
    cin >> n;

    vector<int> nums(n);
    for (int i = 0; i < n; i++)
    {
        int num;
        cin >> num;
        nums[i] = num;
    }

    int idx = 0;
    stack<int> sequence;
    vector<char> operations;

    for (int i = 1; i <= n; i++)
    {
        sequence.push(i);
        operations.emplace_back('+');

        while (sequence.size() > 0 && sequence.top() == nums[idx])
        {
            sequence.pop();
            operations.emplace_back('-');
            idx++;
        }
    }

    if (sequence.size() > 0)
    {
        cout << "NO";
        return 0;
    }

    for (auto& operation : operations)
        cout << operation << "\n";
}