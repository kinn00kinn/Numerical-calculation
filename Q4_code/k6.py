import matplotlib.pyplot as plt
import math


def main():
    x = [0]
    y2 = [1]
    z2 = [1]
    y4 = [1]
    z4 = [1]

    xmax = 5
    h = 0.5
    n = int((xmax-x[0])/h)

    def ft(x):
        return 2/3 * math.e ** (- x / 2) * (math.cos(math.sqrt(3) / 2 * x) + math . sqrt(3) * math . sin(math . sqrt(3) / 2 * x)) + math .e ** x / 3

    def f1(x, y, z):
        return z

    def f2(x, y, z):
        return math.e ** x - y - z

    for j in range(n):
        ky = [0]
        kz = [0]

        ky.append(h * f1(x[j], y2[j], z2[j]))
        kz.append(h * f2(x[j], y2[j], z2[j]))
        ky.append(h * f1(x[j] + h / 2, y2[j] + ky[1]/2, z2[j] + kz[1]/2))
        kz.append(h * f2(x[j] + h / 2, y2[j] + ky[1]/2, z2[j] + kz[1]/2))
        y2.append(y2[j] + ky[2])
        z2.append(z2[j] + kz[2])
        x.append(x[j] + h)

    for j in range(n):
        ky = [0]
        kz = [0]

        ky.append(h * f1(x[j], y4[j], z4[j]))
        kz.append(h * f2(x[j], y4[j], z4[j]))
        ky.append(h * f1(x[j] + h / 2, y4[j] + ky[1]/2, z4[j] + kz[1]/2))
        kz.append(h * f2(x[j] + h / 2, y4[j] + ky[1]/2, z4[j] + kz[1]/2))
        ky.append(h * f1(x[j] + h / 2, y4[j] + ky[2]/2, z4[j] + kz[2]/2))
        kz.append(h * f2(x[j] + h / 2, y4[j] + ky[2]/2, z4[j] + kz[2]/2))
        ky.append(h * f1(x[j]+h, y4[j] + ky[3], z4[j] + kz[3]))
        kz.append(h * f2(x[j]+h, y4[j] + ky[3], z4[j] + kz[3]))
        y4.append(y4[j]+(ky[1]+2 * ky[2]+2 * ky[3] + ky[4]) / 6)
        z4.append(z4[j]+(kz[1]+2 * kz[2]+2 * kz[3] + kz[4]) / 6)

    yt = []
    for i in range(len(x)):
        yt.append(ft(x[i]))

    plt.plot(x, z2, label="2次のルンゲクッタ法")
    plt.plot(x, z4, label="4次のルンゲクッタ法")
    plt.plot(x, yt, label="真値")
    plt.xlabel("x")
    plt.ylabel("y")
    plt.legend(prop={"family": "MS Gothic"})
    plt.grid()
    plt.show()


if __name__ == "__main__":
    main()
