#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

string add(string num1, string num2)
{
    int len1 = num1.length() - 1;
    int len2 = num2.length() - 1;
    int carry = 0;

    string result = "";
    while (len1 >= 0 || carry)
    {
        int sum = carry;
        if (len1 >= 0)
            sum += num1[len1--] - '0';
        if (len2 >= 0)
            sum += num2[len2--] - '0';
        
        carry = sum / 10;
        result += sum % 10 + '0';
    }

    reverse(result.begin(), result.end());
    return result;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    long long n;
    cin >> n;
    
    if (n <= 1)
    {
        cout << n;
        return 0;
    }
    
    string fn2 = "0";
    string fn1 = "1";
    for (long long i = 2; i <= n; ++i)
    {
        string tmp = fn1;
        fn1 = add(fn1, fn2);
        fn2 = tmp;
    }

    cout << fn1;
}