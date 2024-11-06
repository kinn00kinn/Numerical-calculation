#include <bits/stdc++.h>
using namespace std;

int main()
{
    int N = 1000;
    long double S = 0;
    long double a = 1, b = 0;
    long double h = 1.0 / N;

    // 関数
    auto f = [&](double x)
    {
        return 4.0 / (1.0 + x * x);
    };

    // 台形公式
    for (int i = 0; i < N; i++)
    {
        S += h / 2.0 * (f(b + i * (a - b) / N) + f(b + (i + 1) * (a - b) / N));
    }

    cout << S << endl;
}