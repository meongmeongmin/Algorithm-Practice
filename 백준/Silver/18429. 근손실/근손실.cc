#include <iostream>
#include <vector>
#include <random>

using namespace std;

int N, K;
int weights[8];
bool visited[8] = { false };

int answer = 0;

void solve(int toPick, int sum)
{
	if (toPick == N)
	{
		++answer;
		return;
	}

	for (int i = 0; i < N; ++i)
	{
		if (visited[i])
			continue;

		int s = sum + weights[i] - K;
		if (s < 0)
			continue;

		visited[i] = true;
		solve(toPick + 1, s);
		visited[i] = false;
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> K;
	for (int i = 0; i < N; ++i)
		cin >> weights[i];

	solve(0, 0);
	cout << answer;
}