# 課題3.5
from math import fabs
import math
import numpy as np
import matplotlib . pyplot as plt


def main():
    c = [[-2.01, 1, 0, 0, 0, 0, 0, 0, 0, 0.001],
         [1, -2.01, 1, 0, 0, 0, 0, 0, 0, 0.002],
         [0, 1, -2.01, 1, 0, 0, 0, 0, 0, 0.003],
         [0, 0, 1, -2.01, 1, 0, 0, 0, 0, 0.004],
         [0, 0, 0, 1, -2.01, 1, 0, 0, 0, 0.005],
         [0, 0, 0, 0, 1, -2.01, 1, 0, 0, 0.006],
         [0, 0, 0, 0, 0, 1, -2.01, 1, 0, 0.007],
         [0, 0, 0, 0, 0, 0, 1, -2.01, 1, 0.008],
         [0, 0, 0, 0, 0, 0, 0, 1, -2.01, -0.991]]

    n = len(c)
    x = []

    def f(x):
        return (math .e ** x - math . e ** (- x)) / 2 - x + (math .e ** x - math .e ** (- x)) / (math .e - math . e ** (-1)) * ((
            math .e ** (-1) - math .e) / 2+2)

    def pivoting(i):
        for j in range(n - 1):
            maxnum = j
            if fabs(c[j][i]) < fabs(c[j + 1][i]):
                maxnum = j + 1
        for j in range(n + 1):
            c[i][j], c[maxnum][j] = c[maxnum][j], c[i][j]

    for i in range(n):
        for j in range(n):
            if fabs(c[i][i]) < fabs(c[i][j]):
                pivoting(i)

    for k in range(0, n):
        for i in range(0, n):
            if i != k:
                C = c[i][k] / c[k][k]
                for j in range(k, n + 1):
                    c[i][j] = c[i][j] - c[k][j] * C

    for i in range(0, n):
        x. append(c[i][n] / c[i][i])

    x. insert(0, 0)
    x. append(1)

    xt = np . arange(0, 1.1, 0.1)
    yt = []
    for i in range(len(xt)):
        yt.append(x[i]-f(xt[i]))

    plt.plot(xt, yt, label="真値")
    #plt.plot(xt, x, label="近似値")
    plt.xlabel("x")
    plt.ylabel("y")
    plt.legend(prop={"family": "MS Gothic"})
    plt.grid()
    plt.show()


if __name__ == "__main__":
    main()
