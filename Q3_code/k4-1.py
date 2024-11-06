import matplotlib.pyplot as plt


def main():
    x = [1]
    y1 = [1]
    y2 = [1]
    y3 = [1]
    y4 = [1]

    xmax = 20
    h = 0.5
    n = int((xmax - x[0])/h)

    def f(x, y):
        return y/x*2

    def ft(x):
        return x**2

    i = -1
    while True:
        i += 1
        y1.append(y1[i]+h*f(x[i], y1[i]))
        x.append(x[i]+h)
        if x[i+1] >= xmax:
            break

    for j in range(n):
        k = [0]
        k. append(h*f(x[j], y2[j]))
        k. append(h*f(x[j] + h / 2, y2[j] + k[1]/2))
        y2 . append(y2[j] + k[2])

    for j in range(n):
        k = [0]
        k. append(h*f(x[j], y3[j]))
        k. append(h*f(x[j] + h / 2, y3[j] + k[1]/2))
        k. append(h*f(x[j]+h, y3[j]+2 * k[2] - k[1]))
        y3 . append(y3[j]+(k[1]+4 * k[2] + k[3]) / 6)

    for j in range(n):
        k = [0]
        k. append(h*f(x[j], y4[j]))
        k. append(h*f(x[j] + h / 2, y4[j] + k[1]/2))
        k. append(h*f(x[j] + h / 2, y4[j] + k[2]/2))
        k. append(h*f(x[j]+h, y4[j] + k[3]))
        y4 . append(y4[j]+(k[1]+2 * k[2]+2 * k[3] + k[4]) / 6)

    yt = []
    for i in range(len(x)):
        yt.append(ft(x[i]))
    for j in range(len(x)):
        y1[j] = yt[j] - y1[j]
        y2[j] = yt[j] - y2[j]
        y3[j] = yt[j] - y3[j]
        y4[j] = yt[j] - y4[j]
    
    plt.plot(x, y1, label="オイラー法")
    plt.plot(x, y2, label="2次のルンゲクッタ法")
    plt.plot(x, y3, label="3次のルンゲクッタ法")
    plt.plot(x, y4, label="4次のルンゲクッタ法")
    # plt.plot(x, yt, label="真値")
    plt.xlabel("x")
    plt.ylabel("y")
    plt.legend(prop={"family": "MS Gothic"})
    plt.grid()
    plt.show()


if __name__ == "__main__":
    main()
