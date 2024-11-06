#include <bits/stdc++.h>
using namespace std;

int sub(double epsilon)
{
    double x0 = 1;         // 初期値
    //double epsilon = 0.001; // 誤差
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

    while (1)
    {
        if (abs(fdx(x[k])) < epsilon)
        {
            break;
        }
        //cout << x[k] << " "<<f(x[k]) << " "<<fdx(x[k])<< endl;
        k++;
        x.push_back(x[k - 1] - (f(x[k - 1]) / fdx(x[k - 1])));
        if (abs((x[k] - x[k - 1]) / x[k]) < epsilon)
        {
            break;
        }
    }

    // 出力
    //cout << i << " " << (x[k] )<< endl;
    //cout << x0 << " " << k << endl;
    printf("%1.10lf %1.10lf\n", epsilon, (sqrt(7) - x[k-1]) / sqrt(7) * 100);
    
}

int main()
{
    for(double i = 10; i>1e-10; i=i/10.0){
        sub(i);
    }
    
}