#include <bits/stdc++.h>
using namespace std;

int main()
{
    double epsilon = 1e-6;
    vector<double> x;
    x.push_back(-1.0);
    double h = 4.0;
    int k = 0;

    // 関数
    auto f = [&](double x)
    {
        return x * x - 7;
    };

    // 二分法
    while (epsilon < h)
    {
        h = h / 2.0;
        if (f(x[k]) * f(x[k] + h) < 0)
        {
            x.push_back(x[k]);
        }
        else
        {
            x.push_back(x[k] + h);
        }
        k++;
    }

    // 出力
    cout << x[k] << endl;
}