#include <bits/stdc++.h>
using namespace std;

void sub(int N, int M)
{
    double a = 10, b = 20;

    auto f = [&](double x, double y)
    {
        return x * x * y * y;
    };

    // int N = 1000, M = 1000;

    long double sum = 0;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            sum += f(a * i / N, b * j / M) * (a / N) * (b / M);
        }
    }

    cout << N << " " << M << " " << abs(sum - 888889)<< endl;
}

int main()
{
    int N = 1, M = 1;
    for (int i = 15; i < 17; i++)
    {
        sub(N, M);
        N = N * 2;
        M = M * 2;
    }
    return 0;
}