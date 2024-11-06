#include <bits/stdc++.h>
using namespace std;

int main()
{
    double x0 = 1;          // 初期値
    double epsilon = 0.001; // 誤差
    double epsilon1 = 0.1;
    int k = 0; // 計算回数
    vector<double> x;
    x.push_back(x0);

    // ニュートン法を用いる関数
    auto f = [&](double x)
    {
        return x * x - 7;
    };

    auto fdx = [&](double x)
    {
        return 2 * x;
    };

    // ニュートン法
    while (1)
    {
        if (fdx(x[k]) < epsilon1 || abs(x[k + 1]) - x[k] > abs(x[k] - x[k - 1]))
        {
            break;
        }
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