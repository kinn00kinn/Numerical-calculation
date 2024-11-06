#include <bits/stdc++.h>
using namespace std;

int main()
{
    double epsilon = 0.001; // 誤差
    double epsilon1 = 0.1;
    int k = 0; // 計算回数
    vector<double> x;
    double x0 = 1;
    x.push_back(x0); // 初期値
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

    while (1)
    {
        x.push_back(x[k - 1] - (f(x[k - 1]) / fdx(x[k - 1])));
        if (abs((x[k] - x[k - 1]) / x[k]) < epsilon)
        {
            break;
        }
        cout << k + 1 << " " << x[k] << " " << f(x[k]) << endl;
        k++;
    }

    // 出力
    // cout << epsilon << " " << abs(x[k] - 5.5452) * 100 << " " << k << endl;
    return 0;
}
