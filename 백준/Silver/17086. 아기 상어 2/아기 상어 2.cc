#include <cstring>
#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <climits>
#include <algorithm>

using namespace std;

bool board[50][50];
pair<int, int> shark[2500];
int sharkCount = 0;

int solve(int y, int x)
{
	int result = INT_MAX;
	for (int i = 0; i < sharkCount; ++i)
		result = min(result, max(abs(x - shark[i].second), abs(y - shark[i].first)));
	return (result == INT_MAX ? -1 : result);
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, m;	// 행, 열
	cin >> n >> m;

	int idx = 0;
	for (int r = 0; r < n; ++r)
		for (int c = 0; c < m; ++c)
		{
			cin >> board[r][c];
			if (board[r][c])
			{
				shark[idx] = { r, c };
				++sharkCount;
				++idx;
			}
		}

	int answer = -1;
	for (int r = 0; r < n; ++r)
		for (int c = 0; c < m; ++c)
		{
			if (board[r][c])
				continue;
			answer = max(answer, solve(r, c));
		}

	cout << answer;
}