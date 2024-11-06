import math
import matplotlib.pyplot as plt


def main():
    h = 0.4
    x_max = 6.0
    i = -1
    x = [0]
    y = [1]
    dxdy = [1]
    ans = []

    def fa(x):
        return 2/3 * math .e ** (- x / 2) * (math . cos(math . sqrt(3) / 2 * x) + math . sqrt(3) * math . sin(math . sqrt(3) / 2 * x)) + math .e ** x / 3

    def f1(a, b, c): return c

    def f2(a, b, c): return math.exp(a)-b-c
    
    while (True):
        i += 1
        dxdy.append(dxdy[i] + h*f2(x[i], y[i], dxdy[i]))
        y.append(y[i] + h*f1(x[i], y[i], dxdy[i]))
        x.append(x[i] + h)
        if (x[i] > x_max):
            break

    for i in range(len(x)):
        ans.append(fa(x[i]))

    plt.plot(x, y, label="近似値")
    plt.plot(x, ans, label="真値")
    plt.xlabel("x")
    plt.ylabel("y")
    plt.grid()
    plt.legend(prop={"family": "MS Gothic"})
    plt.show()


if __name__ == "__main__":
    main()
