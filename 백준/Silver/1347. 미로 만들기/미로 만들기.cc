#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int l;
    cin >> l;

    string cmd;
    cin >> cmd;

    // 상, 좌, 하, 우
    int dy[4] = { -1, 0, 1, 0 };
    int dx[4] = { 0, -1, 0, 1 };

    int dir = 2;    // 하
    pair<int, int> pos = { 0, 0 };  // y, x

    vector<pair<int, int>> delta;
    delta.push_back(pos);

    int minY = 0;
    int maxY = 0;
    int minX = 0;
    int maxX = 0;

    for (const char& c : cmd)
    {
        if (c == 'F')
        {
            int y = pos.first + dy[dir];
            int x = pos.second + dx[dir];
            pos = { y, x };
            delta.push_back(pos);

            if (minY > y)
                minY = y;

            if (maxY < y)
                maxY = y;

            if (minX > x)
                minX = x;

            if (maxX < x)
                maxX = x;
        }
        else if (c == 'R')
            dir = (dir - 1 + 4) % 4;
        else
            dir = (dir + 1 + 4) % 4;
    }

    int ySize = -minY + maxY + 1;
    int xSize = -minX + maxX + 1;

    vector<vector<char>> board(ySize, vector<char>(xSize, '#'));
    for (const pair<int, int>& p : delta)
    {
        int y = p.first + -minY;
        int x = p.second + -minX;
        board[y][x] = '.';
    }

    for (const vector<char>& v : board)
    {
        for (const char& c : v)
            cout << c;
        cout << '\n';
    }

    return 0;
}