#include <cstring>
#include <iostream>
#include <string>
#include <vector>
#include <cmath>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	long long x, y;
	cin >> x >> y;
	long long z = (y * 100) / x;
	if (z >= 99) 
	{
		cout << -1;
		return 0;
	}

	long long low = 1, high = 1000000000;
	long long answer = -1;
	while (low <= high)
	{
		long long mid = (low + high) / 2;
		long long zz = ((y + mid) * 100) / (x + mid);

		if (zz > z)
		{
			answer = mid;
			high = mid - 1;
		}
		else
			low = mid + 1;
	}

	cout << answer << "\n";
}