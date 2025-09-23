#include <iostream>
#include <vector>
#include <string>
#include <map>

using namespace std;

int main()
{
	int size = 5;
	vector<vector<int>> board(size, vector<int>(size));
	map<int, pair<int, int>> pos;

	for (int r = 0; r < size; r++)
		for (int c = 0; c < size; c++)
		{
			int num;
			cin >> num;

			board[r][c] = num;
			pos[num] = { r, c };
		}

	int numsSize = size * size;
	int diag = size - 1;

	vector<int> rowCount(size, 0);
	vector<int> colCount(size, 0);
	vector<int> diagCount(2, 0);	// [0]: ↘, [1]: ↙

	int bingoCount = 0;
	int result = 0;

	for (int i = 0; i < numsSize; i++)
	{
		int num;
		cin >> num;

		int r = pos[num].first;
		int c = pos[num].second;

		rowCount[r]++;
		colCount[c]++;

		if (r == c)
		{
			if (++diagCount[0] == size)
				bingoCount++;
		}
		
		if ((r + c) == diag)
		{
			if (++diagCount[1] == size)
				bingoCount++;
		}

		if (rowCount[r] == size)
			bingoCount++;

		if (colCount[c] == size)
			bingoCount++;

		if (result == 0 && bingoCount >= 3)
			result = i + 1;
	}

	cout << result << endl;
}