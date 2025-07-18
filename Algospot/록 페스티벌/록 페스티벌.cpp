#include <iostream>
#include <vector>
#include <string>
#include <iomanip>

using namespace std;

int main()
{
#pragma region I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
#pragma endregion

    int c;  // 테스트 케이스의 수
    cin >> c;

    vector<double> minAvgs;

    for (int i = 0; i < c; i++)
    {
        int n;  // 공연장을 대여할 수 있는 날의 수
        int l;  // 이미 섭외한 공연 팀의 수
        cin >> n >> l;

        vector<int> costs(n);   // 날짜별 공연장 대여 비용
        for (int j = 0; j < n; j++)
            cin >> costs[j];

        double minAvg = 3.40282e+38;
        for (int den = l; den <= n; den++)
        {
            int windowSum = 0;
            for (int j = 0; j < den; j++)
                windowSum += costs[j];

            int minSum = windowSum;
            for (int j = den; j < n; j++)
            {
                windowSum += costs[j] - costs[j - den];
                if (windowSum < minSum)
                    minSum = windowSum;
            }

            double avg = (double)minSum / den;
            if (minAvg > avg)
                minAvg = avg;
        }

        minAvgs.push_back(minAvg);
    }

    for (double mac : minAvgs)
        cout << fixed << setprecision(11) << mac << "\n";

    return 0;
}
