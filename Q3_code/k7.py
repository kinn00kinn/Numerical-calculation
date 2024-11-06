import math
import matplotlib.pyplot as plt


def main():
    E = 100
    R = 15
    L = 500*10**(-3)
    r = 10
    x = [0]
    y = [E / r]
    yt = []
    y4 = [E/r]
    xmax = 0.3
    h = 0.01
    n = int((xmax - x[0]) / h)
    i = -1

    def f(x, y):
        return (E - R * y) / L

    def ft(x):
        return E/R + (E/r - E/R) * math.e ** (- R/L * x)

    while True:
        i += 1
        y. append(y[i] + h * f(x[i], y[i]))
        x. append(x[i] + h)
        if x[i + 1] > xmax:
            break

    i = n
    for j in range(i):
        k = [0]
        k.append(h*f(x[j], y4[j]))
        k.append(h*f(x[j] + h / 2, y4[j] + k[1]/2))
        k.append(h*f(x[j] + h / 2, y4[j] + k[2]/2))
        k.append(h*f(x[j]+h, y4[j] + k[3]))
        y4.append(y4[j]+(k[1]+2 * k[2]+2 * k[3] + k[4]) / 6)

    for i in range(len(x)):
        yt . append(ft(x[i]))

    plt.plot(x, y, label="オイラー法")
    plt.plot(x, y4, label="4次のルンゲクッタ法")
    plt.plot(x, yt, label="真値")
    plt.xlabel("t")
    plt.ylabel("A")
    plt.grid()
    plt.legend(prop={"family": "MS Gothic"})
    plt.show()


if __name__ == "__main__":
    main()
