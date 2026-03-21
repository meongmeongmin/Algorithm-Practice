#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <unordered_map>
#include <sstream>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	cin >> N;
	
	unordered_map<string, int> map;
	for (int i = 0; i < N; ++i)
	{
		string w;
		cin >> w;

		string key = "";
		if (w.size() <= 2)
			key = w;
		else 
		{
			key += w.front();
			key += w.back();
			string mid = w.substr(1, w.size() - 2);
			sort(mid.begin(), mid.end());
			key += mid;
		}

		++map[key];
	}

	int M;
	cin >> M;
	cin.ignore();
	
	for (int i = 0; i < M; ++i)
	{
		string str;
		getline(cin, str);
		stringstream ss(str);
		string w;

		int answer = 0;
		while (ss >> w)
		{
			string key = "";
			if (w.size() <= 2)
				key = w;
			else
			{
				key += w.front();
				key += w.back();
				string mid = w.substr(1, w.size() - 2);
				sort(mid.begin(), mid.end());
				key += mid;
			}

			if (map.count(key) == false)
			{
				answer = 0;
				break;
			}
			
			answer = answer > 0 ? answer * map[key] : map[key];
		}

		cout << answer << '\n';
	}
}