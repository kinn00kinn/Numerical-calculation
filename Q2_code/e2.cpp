#include <bits/stdc++.h>
using namespace std;

double sub(double h)
{
    double epsilon = 0.001;
    double const_h = h;
    vector<double> x;
    x.push_back(-5.0);
    // double h = 4.0;
    int k = 0;

    // 関数
    auto f = [&](double x)
    {
        return x * x - 7;
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

        // cout << k + 1 << " " << x[k] << " " << h << endl;
        k++;
    }

    // 出力
    cout << const_h << " " << h << " " << x[k] << " " << k << endl;
    return 0;
    // for(int i=0; i<x.size(); i++){
    //     cout << x[i] << endl;
    // }
}

int main()
{
    double h = 0;
    for (int i = 0; i < 300; i++)
    {
        h += 0.1;
        sub(h);
    }
}