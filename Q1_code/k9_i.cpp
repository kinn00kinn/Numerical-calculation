#include <bits/stdc++.h>
using namespace std;

/*変数初期化*/
// 解ベクトル
vector<double> x(12, 1);

// 拡大行列C(A,E)
vector<vector<double>> C = {{-4, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                            {1, -4, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                            {0, 1, -4, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                            {1, 0, 0, -4, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0},
                            {0, 1, 0, 1, -4, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0},
                            {0, 0, 1, 0, 1, -4, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0},
                            {0, 0, 0, 1, 0, 0, -4, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0},
                            {0, 0, 0, 0, 1, 0, 1, -4, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0},
                            {0, 0, 0, 0, 0, 1, 0, 1, -4, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0},
                            {0, 0, 0, 0, 0, 0, 1, 0, 0, -4, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0},
                            {0, 0, 0, 0, 0, 0, 0, 1, 0, 1, -4, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0},
                            {0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1, -4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1}};
vector<double> b{
    -100, -100, -100, 0, 0, 0, 0, 0, 0, 100, 100, 100};

// ランク
int n = C.size();

// 結果出力用関数
void print_result(vector<double> x)
{
    int n = x.size();
    for (int i = 0; i < n - 1; i++)
    {
        cout << x[i] << " ";
    }
    cout << x[n - 1] << endl;
}

int main()
{
    /*逆行列を用いた解法*/
    double ctmp;
    for (int k = 0; k < n; k++)
    {
        ctmp = C[k][k];
        for (int j = 0; j < 2 * n; j++)
        {
            C[k][j] = C[k][j] / ctmp;
        }
        for (int i = 0; i < n; i++)
        {
            if (i != k)
            {
                ctmp = C[i][k];
                for (int j = k; j < 2 * n; j++)
                {
                    C[i][j] = C[i][j] - C[k][j] * ctmp;
                }
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        x[i] = 0;
        for (int j = 0; j < n; j++)
        {
            x[i] = x[i] + C[i][n + j] * b[j];
        }
    }

    // 結果表示
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cout << C[i][j+n] <<"&";
        }
        cout << endl;
    }
    print_result(x);
    return 0;
}