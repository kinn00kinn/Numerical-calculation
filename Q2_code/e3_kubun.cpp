#include <bits/stdc++.h>
using namespace std;

void sub(int N)
{
    //int N = 1000;
    long double S = 0;
    long double a = 1, b = 0;

    // 関数
    auto f = [&](double x)
    {
        return 4.0 / (1.0 + x * x);
    };

    for (int i = 0; i < N; i++)
    {
        S += f(b + i * (a - b) / N) * (1.0 / N);
    }

    cout << N << " " << abs(S - M_PI)*100 << endl;
}

int main()
{
    int N = 1;
    for (int i = 0; i < 9; i++)
    {
        sub(N);
        N = N * 10;
    }
}