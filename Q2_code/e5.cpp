#include <bits/stdc++.h>
using namespace std;

int sub(double h)
{
    double epsilon = 1e-5;
    vector<double> x;
    x.push_back(1.2 * 1e-3);
    // double h = 1;
    int k = 0;
    double const_h = h;

    double E = 1;
    double R = 1095;
    double L = 0.3;
    double C = 1e-6;
    // 関数
    auto f = [&](double t)
    {
        return (double)(E / L) * t * exp(-R * t / (2 * L)) - (E / (exp(1) * R));
    };

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
    cout << const_h << " " << h << " " << k <<" "<< x[k]<< endl;
}

int main()
{
    for (double h = 0.000001; h < 0.002; h = h + 0.00001)
    {
        sub(h);
    }
    return 0;
}