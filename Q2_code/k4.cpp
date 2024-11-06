#include <bits/stdc++.h>
using namespace std;

int main()
{
    double epsilon = 0.001; // 誤差
    int k = 0;              // 計算回数
    vector<double> x;
    x.push_back(2.0); // 初期値
    double E = 1, R = 100 * 1e3, C = 80 * 1e-6;

    // ニュートン法を用いる関数
    auto f = [&](double t)
    {
        return (E / R) * exp(t / (-C * R)) - (E / (2 * R));
    };

    auto fdx = [&](double t)
    {
        return (-E / (C * R * R)) * exp(t / (-C * R));
    };

    // ニュートン法
    while (1)
    {
        k++;
        x.push_back(x[k - 1] - (f(x[k - 1]) / fdx(x[k - 1])));
        if (abs((x[k] - x[k - 1]) / x[k]) < epsilon)
        {
            break;
        }
    }

    // 出力
    cout << x[k] << endl;
}