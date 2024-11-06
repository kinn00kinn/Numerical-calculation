#include <bits/stdc++.h>
using namespace std;

int main()
{
    int N = 1000;
    long long double S = 0;
    long long double a = 1, b = 0;

    // 関数
    auto f = [&](double x)
    {
        return 4.0 / (1.0 + x * x);
    };

    // 区分求積法
    for (int i = 0; i < N; i++)
    {
        S += f(b + i * (a - b) / N) * (1.0 / N);
    }

    cout << S << endl;
}