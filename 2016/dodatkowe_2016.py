import math

a, b, r = 200, 200, 200


def rownanie(x, y):
    a1 = (x - a) ** 2
    a2 = (y - b) ** 2
    if a1 + a2 < r ** 2:
        return True
    else:
        return False


def pd_1(f):
    count = 0
    for line in f:
        x, y = line.rstrip().split(" ")
        x, y = int(x), int(y)
        if (rownanie(x, y)):
            count += 1
    # print("4.1. Jest ", str(count), " punktow nalezacych do wnetrza kola")
    return count


def pd_2(ilosc_pierw_pkt=100):
    f = open("mat/punkty.txt")
    y = f.readlines()[0:ilosc_pierw_pkt]
    f.close()

    n_kolo = pd_1(y)
    n_kwadrat = ilosc_pierw_pkt

    PI = 4 * n_kolo / n_kwadrat
    print("Dla ", str(ilosc_pierw_pkt), " PI wynosi ", round(PI, 4))
    return PI


def pd_3():
    index = 0
    v = open("mat/wyniki_2016.txt", "w")
    while index != 1700:
        index += 1
        PI = pd_2(index)

        blad = abs(math.pi - PI)
        v.write(str(round(blad, 4)) + "\n")
    v.close()


# pd_3()