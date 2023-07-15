#include <bits/stdc++.h>
using namespace std;

/*変数初期化*/
//解ベクトル
vector<double> x{
    1, 1};

//係数行列
vector<vector<double>> a = {
    {3, -1},
    {2, 4},
};
vector<double> b{
    2, 1};

//誤差率
double epsilon = 0.01;

//ランク
int n = a.size();
int c=0;

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
    /*ガウス・ザイデル法*/
    double S = 0, X = 0;
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
            if (abs((X - x[i]) / X) < epsilon)
                M++;
            x[i] = X;
            c++;
        }
    }

    // 結果表示
    print_result(x);
    cout << c;

    return 0;
}
