#include <iostream>
#include <cmath>

using namespace std;

bool isPrimeNum(int num)
{
    if (num <= 1)
        return false;

    for (int i = 2; i <= sqrt(num); i++)
    {
        if (num % i == 0)
            return false;
    }

    return true;
}

int main()
{
    #pragma region I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    #pragma endregion

    int inputCount;
    cin >> inputCount;

    int count = 0;
    for (int i = 0; i < inputCount; i++)
    {
        int num;
        cin >> num;
        if (isPrimeNum(num))
            count++;
    }

    cout << count;
}