#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cmath>
#include <climits>
#include <cstring>

using namespace std;

int N;
int board[100][100];

long long dp[100][100];

long long solve(int y, int x)
{
	if (y >= N || x >= N)
		return 0;
	if (y == N - 1 && x == N - 1)
		return 1;

	long long& result = dp[y][x];
	if (result != -1)
		return result;
	
	result = 0;
	result += solve(y, x + board[y][x]);
	result += solve(y + board[y][x], x);
	return result;
}

int main()
{
	cin >> N;
	for (int r = 0; r < N; ++r)
		for (int c = 0; c < N; ++c)
			cin >> board[r][c];
	memset(dp, -1, sizeof(dp));
	cout << solve(0, 0);
}