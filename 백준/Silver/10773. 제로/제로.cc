#include <iostream>
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

    stack<int> cog;
    for (int i = 0; i < n; i++)
    {
        int money;
        cin >> money;

        if (money == 0 && cog.empty() == false)
            cog.pop();
        else
            cog.push(money);
    }

    int sum = 0;
    while (cog.empty() == false)
    {
        sum += cog.top();
        cog.pop();
    }

    cout << sum;
}