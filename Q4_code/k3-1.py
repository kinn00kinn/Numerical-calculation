from math import fabs
import math
import numpy as np
import matplotlib . pyplot as plt


def main():
    # 拡大係数行列の入力
    c = [[-2.04, 1, 0, 0, 0, 0, 0, 0, 0, 0],
         [1, -2.04, 1, 0, 0, 0, 0, 0, 0, 0],
         [0, 1, -2.04, 1, 0, 0, 0, 0, 0, 0],
         [0, 0, 1, -2.04, 1, 0, 0, 0, 0, 0],
         [0, 0, 0, 1, -2.04, 1, 0, 0, 0, 0],
         [0, 0, 0, 0, 1, -2.04, 1, 0, 0, 0],
         [0, 0, 0, 0, 0, 1, -2.04, 1, 0, 0],
         [0, 0, 0, 0, 0, 0, 1, -2.04, 1, 0],
         [0, 0, 0, 0, 0, 0, 0, 1, -2.04, -0.25]]

    # 結果を格納するリストの作成
    n = len(c)
    x = []

    def f(x):
        return (math .e ** (2 * x) - math . e ** (-2 * x)) / (math .e ** 2 - math . e ** (-2)) / 4

    # ピボット選択関数
    def pivoting(i):
        for j in range(n - 1):
            maxnum = j
            if fabs(c[j][i]) < fabs(c[j + 1][i]):
                maxnum = j + 1
        for j in range(n + 1):
            c[i][j], c[maxnum][j] = c[maxnum][j], c[i][j]

    # ピボット選択が必要か否かを判定している
    for i in range(n):
        for j in range(n):
            if fabs(c[i][i]) < fabs(c[i][j]):
                pivoting(i)

    # ガウス・ジョルダン法
    for k in range(0, n):
        for i in range(0, n):
            if i != k:
                C = c[i][k] / c[k][k]
                for j in range(k, n + 1):
                    c[i][j] = c[i][j] - c[k][j] * C

    # 結果の格納
    for i in range(0, n):
        x. append(c[i][n] / c[i][i])

    # 結果の出力
    x. insert(0, 0)
    x. append(0.25)

    xt = np . arange(0.0, 1.1, 0.1)
    yt = []

    for i in range(len(xt)):
        yt . append(x[i]-f(xt[i]))

    plt.plot(xt, yt, label="真値と解析解の誤差")
    plt.xlabel("x")
    plt.ylabel("y")
    plt.legend(prop={"family": "MS Gothic"})
    plt.grid()
    plt.show()


if __name__ == "__main__":
    main()
