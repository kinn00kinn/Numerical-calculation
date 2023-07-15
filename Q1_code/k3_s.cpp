#include <bits/stdc++.h>
using namespace std;

/*変数初期化*/
//解ベクトル
vector<double> x{
    1, 1, 1};

//係数行列
//係数行列
vector<vector<double>> a = {
    {2, 1, 1},
    {0, 2, 1},
    {1, 1, 1},
};
vector<double> b{
    1, 2, 2};

//誤差率
double epsilon = 0.1;

//加速度パラメータ
double varepsilon = 2.0;

//ランク
int n = a.size();

// 結果出力用関数
void print_result(vector<double> x)
{
    int n = x.size();
    for (int i = 0; i < n - 1; i++)
    {
        printf("%3.2lf ", x[i]);
    }
    cout << x[n - 1] << endl;
}

int main()
{
    /*SOR法*/
    double S = 0.0, X = 0.0;
    int M = 0;

    // 終了判定
    while (n != M)
    {
        M = 0;
        for (int i = 0; i < n; i++)
        {
            S = 0.0;
            for (int j = 0; j < n; j++)
                S = S + a[i][j] * x[j];
            X = (b[i] - S + a[i][i] * x[i]) / a[i][i];
            // 加速パラメータ
            X = x[i] + varepsilon * (X - x[i]);
            if (abs((X - x[i]) / X) < epsilon)
                M++;
            x[i] = X;
        }
    }

    // 結果表示
    print_result(x);

    return 0;
}
