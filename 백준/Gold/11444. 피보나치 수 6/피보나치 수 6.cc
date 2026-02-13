#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const long long MOD = 1000000007;

struct Matrix 
{
    long long a, b, c, d;
};

Matrix multiply(Matrix x, Matrix y)
{
    Matrix result;
    result.a = (x.a * y.a + x.b * y.c) % MOD;
    result.b = (x.a * y.b + x.b * y.d) % MOD;
    result.c = (x.c * y.a + x.d * y.c) % MOD;
    result.d = (x.c * y.b + x.d * y.d) % MOD;
    return result;
}

Matrix solve(Matrix base, long long n)
{
    if (n <= 1)
        return base;

    Matrix half = solve(base, n / 2);
    Matrix result = multiply(half, half);

    if (n % 2 == 1)
        result = multiply(result, base);
    return result;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    long long n;
    cin >> n;
    Matrix fib = { 1, 1, 1, 0 };
    Matrix result = solve(fib, n);
    cout << result.b;   // F(n)
}