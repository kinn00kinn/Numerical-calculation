import math
import matplotlib.pyplot as plt


def main():
    h = 0.1
    x_max = 2.5
    i = -1
    x = [0]
    y = [1]
    ans = []

    def f(a, b): return a*b

    while (True):
        i += 1
        y.append(y[i]+h*f(x[i], y[i]))
        x.append(x[i] + h)
        if (x[i] > x_max):
            break

    for i in range(len(y)):
        ans.append(math.e**(x[i]**2/2))

    plt.plot(x, y, label="近似値")
    plt.plot(x, ans, label="真値")
    plt.xlabel("x")
    plt.ylabel("y")
    plt.grid()
    plt.legend(prop={"family": "MS Gothic"})
    plt.show()


if __name__ == "__main__":
    main()
