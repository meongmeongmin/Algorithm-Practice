#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int main() 
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;
    int range = n - 1;

    vector<int> distance(range);
    for (int i = 0; i < range; ++i)
        cin >> distance[i];

    vector<int> cost(n);
    for (int i = 0; i < n; ++i)
        cin >> cost[i];

    // 처음
    int answer = distance[0] * cost[0];
    
    int min = cost[0];
    for (int i = 1; i < range; ++i)
    {
        if (min > cost[i])
            min = cost[i];
        answer += distance[i] * min;
    }

    cout << answer;
}