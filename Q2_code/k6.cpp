#include <bits/stdc++.h>
using namespace std;

int main()
{
    double a = 10, b = 20;

    auto f = [&](double x, double y)
    {
        return x * x * y * y;
    };

    int N = 1000, M = 1000;

    long double sum = 0;
    // 二重積分(区分求積法)
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            sum += f(a * i / N, b * j / M) * (a / N) * (b / M);
        }
    }

    cout << sum << endl;
}