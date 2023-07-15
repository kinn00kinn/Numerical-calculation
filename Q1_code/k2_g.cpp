#include <bits/stdc++.h>
using namespace std;

/*変数初期化*/
//解ベクトル
vector<double> x{
    1, 1};

//係数行列
vector<vector<double>> a = {
    {4, 6},
    {5, 3},
};
vector<double> b{
    6, 1};

//誤差率
double epsilon = 0.1;

//ランク
int n = a.size();

/*ピボット選択関数*/
void pivot()
{
    int n = a.size();
    int max, max_pos, tmp_s;
    vector<double> tmp_v;
    // pivot
    for (int i = 0; i < n; i++)
    {
        max = abs(a[i][0]);
        max_pos = 0;
        for (int j = 0; j < n; j++)
        {
            if (max < abs(a[i][j]))
            {
                max = a[i][j];
                max_pos = j;
            }
        }
        // a
        tmp_v = a[max_pos];
        a[max_pos] = a[i];
        a[i] = tmp_v;
        // b
        tmp_s = b[max_pos];
        b[max_pos] = b[i];
        b[i] = tmp_s;
    }
}

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
    /*ピボット操作*/
    pivot();

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
        }
    }

    // 結果表示
    print_result(x);

    return 0;
}
