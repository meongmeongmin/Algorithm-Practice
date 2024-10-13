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

    stack<int> stack;
    vector<int> operationResults;

    for (int i = 0; i < n; i++)
    {
        string command;
        cin >> command;
        
        if (command == "push")
        {
            int num;
            cin >> num;
            stack.push(num);
        }
        else if (command == "pop")
        {
            if (stack.empty() == false)
            {
                operationResults.emplace_back(stack.top());
                stack.pop();
            }
            else
                operationResults.emplace_back(-1);
        }
        else if (command == "size")
            operationResults.emplace_back(stack.size());
        else if (command == "empty")
            operationResults.emplace_back(stack.empty() ? 1 : 0);
        else if (command == "top")
            operationResults.emplace_back(stack.empty() == false ? stack.top() : -1);
    }

    for (const auto& result : operationResults)
        cout << result << "\n";
}