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

	if (dp[y][x] != -1)
		return dp[y][x];
	
	dp[y][x] = 0;
	dp[y][x] += solve(y, x + board[y][x]);
	dp[y][x] += solve(y + board[y][x], x);
	return dp[y][x];
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