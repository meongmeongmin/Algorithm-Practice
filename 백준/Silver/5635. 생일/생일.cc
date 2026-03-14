#include <iostream>
#include <tuple>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;

    int yy = -1, ym = 12, yd = 31;
    int oy = 9999, om = 0, od = 0;
    
    string youngAnswer;
    string oldAnswer;

    for (int i = 0; i < N; ++i)
    {
        string name;
        int dd, mm, yyyy;
        cin >> name >> dd >> mm >> yyyy;

        if (yy < yyyy)
        {
            yy = yyyy;
            ym = mm;
            yd = dd;
            youngAnswer = name;
            continue;
        }
        else if (yy == yyyy && (ym < mm || ym == mm && yd < dd))
        {
            ym = mm;
            yd = dd;
            youngAnswer = name;
            continue;
        }

        if (oy > yyyy)
        {
            oy = yyyy;
            om = mm;
            od = dd;
            oldAnswer = name;
        }
        else if (oy == yyyy && (om > mm || om == mm && od > dd))
        {
            om = mm;
            od = dd;
            oldAnswer = name;
        }
    }

    cout << youngAnswer << '\n' << oldAnswer;
}