#include <iostream>

using namespace std;

int main()
{
    #pragma region I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    #pragma endregion

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < i; j++)
            cout << " ";

        for (int j = 1; j < (n - i) * 2; j++)
            cout << "*";

        cout << endl;
    }
}