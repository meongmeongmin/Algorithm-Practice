#include <cstring>
#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <climits>
#include <algorithm>
#include <queue>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, m;
	cin >> n >> m;

	priority_queue<long long, vector<long long>, greater<long long>> a;
	for (int i = 0; i < n; ++i)
	{
		long long card;
		cin >> card;
		a.push(card);
	}

	for (int i = 0; i < m; ++i)
	{
		long long card = a.top();
		a.pop();
		card += a.top();
		a.pop();
		a.push(card);
		a.push(card);
	}

	long long answer = 0;
	while (!a.empty())
	{
		answer += a.top();
		a.pop();
	}

	cout << answer;
}