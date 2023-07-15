#include <bits/stdc++.h>
using namespace std;

/*変数初期化*/
// 解ベクトル
vector<double> x = {1, 1, 1, 1, 1};

// 拡大係数行列
vector<vector<double>> C = {
    {2, 3, 4, 5, 6, 70},
    {3, 4, 5, 6, 2, 60},
    {6, 2, 3, 4, 5, 60},
    {5, 6, 2, 3, 4, 55},
    {4, 5, 6, 2, 3, 55},
};

// ランク
int n = C.size();

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

    /*ガウス・ジョルダン法*/
    double ctmp;
    for (int k = 0; k < n; k++)
    {
        for (int i = 0; i < n; i++)
        {
            if (i != k)
            {
                ctmp = C[i][k] / C[k][k];
                for (int j = k; j < n + 1; j++)
                {
                    C[i][j] = C[i][j] - (C[k][j] * ctmp);
                }
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        x[i] = C[i][n] / C[i][i];
    }

    // 結果表示
    print_result(x);

    return 0;
}
