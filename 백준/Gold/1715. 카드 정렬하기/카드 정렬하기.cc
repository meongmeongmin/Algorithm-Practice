#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main()
{
    #pragma region I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    #pragma endregion

    int n;
    cin >> n;

    priority_queue<int, vector<int>, greater<int>> deckPq;   // 카드 묶음들
    for (int i = 0; i < n; i++)
    {
        int deck;
        cin >> deck;
        deckPq.push(deck);
    }

    int compareCount = 0;   // 최소 비교 횟수
    while (deckPq.size() >= 2)
    {
        int sum = deckPq.top();
        deckPq.pop();
        sum += deckPq.top();
        deckPq.pop();

        deckPq.push(sum);
        compareCount += sum;
    }

    cout << compareCount;
}