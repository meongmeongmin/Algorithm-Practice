#include <iostream>
#include <vector>
#include <map>
#include <string>

using namespace std;

// 분수 a/b의 소수 표현을 출력한다.
// a >= 0, b > 0이라고 가정함
string convertDecimal(int mole, int deno)
{
	string decimal = to_string(mole / deno) + ".";	// 첫 번째와 두 번째 사이에 소수점을 찍는다.
	mole = (mole % deno) * 10;

	int index = decimal.length();
	map<int, int> seens;

	// 소수점 이하 구하기
	while (mole > 0)
	{
		// 순환 소수 찾음
		if (seens.count(mole))
		{
			int start = seens[mole];
			decimal.insert(start, "(");
			decimal += ")";
			return decimal;
		}

		seens[mole] = index++;
		decimal += to_string(mole / deno);
		mole = (mole % deno) * 10;
	}

	return decimal + "(0)";
}

int main(int argc, char* argv[])
{
	int t;
	cin >> t;

	vector<string> decimals;
	for (int i = 0; i < t; i++)
	{
		int mole, deno;
		cin >> mole >> deno;
		decimals.push_back(convertDecimal(mole, deno));
	}

	for (string d : decimals)
		cout << d << '\n';
}