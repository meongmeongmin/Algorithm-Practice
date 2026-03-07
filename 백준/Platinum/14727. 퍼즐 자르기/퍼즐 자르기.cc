#include <iostream>
#include <vector>

using namespace std;

vector<long long> heights;

long long solve(int left, int right)
{
	if (left == right)
		return heights[left];

	int mid = (left + right) / 2;
	long long result = max(solve(left, mid), solve(mid + 1, right));

	int start = mid;
	int end = mid + 1;
	long long h = min(heights[start], heights[end]);

	result = max(result, h * 2);
	while (start > left || end < right)
	{
		if (end < right && (start == left || heights[start - 1] < heights[end + 1]))
		{
			++end;
			h = min(h, heights[end]);
		}
		else
		{
			--start;
			h = min(h, heights[start]);
		}

		result = max(result, (end - start + 1) * h);
	}

	return result;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	cin >> N;

	heights.resize(N);
	for (int i = 0; i < N; ++i)
		cin >> heights[i];
	cout << solve(0, N - 1);
}