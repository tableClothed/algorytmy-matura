TABELA = []
with open("liczby.txt", "r") as f:
    TABELA = f.readlines()

# TABELA = [int(i.replace("\n", "")) for i in TABELA]


def ZAD_1():
    licz = 0
    for i in TABELA:
        if i.count("0") > i.count("1"):
            licz += 1
    print(f"ZAD1: Takich liczb jest {licz}")


def ZAD_2():
    licz_8, licz_2 = 0, 0
    for i in TABELA:
        if int(i) % 2 == 0:
            licz_2 += 1

        if int(i) % 8 == 0:
            licz_8 += 1
    print(f"ZAD 2: Ilość liczb podzielnych przez 2: {licz_2}")
    print(f"ZAD 2: Ilość liczb podzielnych przez 8: {licz_8}")

def ZAD_3():
    l_max, l_min = 0, int(TABELA[0])
    l_max_wiersz, l_min_wiersz = 0, 0

    for i, liczba in enumerate(TABELA):
        if int(liczba) < l_min:
            l_min = int(liczba)
            l_min_wiersz = i+1
        if int(liczba) > l_max:
            l_max = int(liczba)
            l_max_wiersz = i+1

    print(f"ZAD 3: Największą liczba stoi w wierszu {l_max_wiersz} i ma postać: \n{l_max}")
    print(f"ZAD 3: Najmniejsza liczba stoi w wierszu {l_min_wiersz} i ma postać: \n{l_min}")


if __name__ == "__main__":
    ZAD_1()

    print("\n")

    ZAD_2()

    print("\n")

    ZAD_3()