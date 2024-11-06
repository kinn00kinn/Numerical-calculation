#include <bits/stdc++.h>
using namespace std;

int main()
{
    int N = 1000;
    double S = 0;
    double a = 1, b = 0;
    double h = 1.0 / N;

    // 関数
    auto f = [&](double x)
    {
        return 4.0 / (1.0 + x * x);
    };

    // シンプソンの公式
    for (int i = 0; i <= N / 2 - 1; i++)
    {
        S += h / 3.0 * (f(b + 2 * i * (a - b) / N) + 4 * f(b + (2 * i + 1) * (a - b) / N) + f(b + (2 * i + 2) * (a - b) / N));
    }

    cout << S << endl;
}