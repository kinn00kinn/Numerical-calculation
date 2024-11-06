#include <bits/stdc++.h>
using namespace std;

void sub(int N)
{
    //int N = 1000;
    long double S = 0;
    long double a = 1, b = 0;
    long double h = 1.0 / N;

    // 関数
    auto f = [&](double x)
    {
        return 4.0 / (1.0 + x * x);
    };

    for (int i = 0; i <= N / 2 - 1; i++)
    {
        S += h / 3.0 * (f(b + 2 * i * (a - b) / N) + 4 * f(b + (2 * i + 1) * (a - b) / N) + f(b + (2 * i + 2) * (a - b) / N));
    }

    cout << N << " " << abs(S - M_PI) * 100 << endl;
}

int main()
{
    int N = 1;
    for (int i = 1; i < 10; i++)
    {
        sub(N);
        N = N * 10;
    }
}