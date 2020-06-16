TABELA = []
with open("liczby.txt", "r") as f:
    for i in f:
        TABELA.append(int(i.replace("\n", "")))

PRZYKLAD = []
with open("przyklad.txt", "r") as f:
    for i in f:
        PRZYKLAD.append(int(i.replace("\n", "")))


def sprawdz_potegi(i):
    if i==1:
        return True
    else:
        if i%3 == 0:
            return sprawdz_potegi(i/3)
        else:
            return False

def zad_1():
    licz_potegi = 0
    for i in TABELA:
        if sprawdz_potegi(i):
            licz_potegi +=1
    print(f"Jest {licz_potegi} takich cyfr")


def silnia(n):
    siln = 1
    for i in range(2, n+1):
        siln *= i
    return siln


def zad_2():
    licz = 0
    for i in TABELA:
        suma = 0
        for cyfra in str(i):
            suma += silnia(int(cyfra))
        if suma == i:
            print(suma)
            licz += 1
    print(f"2: Jest {licz} takich liczb")


def NWD(a, b):
    if b > a: a,b = b, a

    while b > 0:
        m = a % b
        a, b = b, m
    return a
#
# def znajdz_dzielniki(a, b):
#     dz_a, dz_b = [], []
#     for i in range(2, a//2):
#         if a % i == 0:
#             dz_a.append(i)
#     for i in range(2, b//2):
#         if b % i == 0:
#             dz_b.append(i)
#
#     dzielniki = []
#     for i in dz_a:
#         if i in dz_b:
#             dzielniki.append(i)
#     return dzielniki


def zad_3():
    LICZBA_PIERWSZA, DZIELNIK, DLUGOSC = 0, 0, 0
    for i in range(len(TABELA)-1):
        l1 = TABELA[i]
        licz_dlugosc = 1
        dzielniki = NWD(TABELA[i], TABELA[i+1])
        if dzielniki == 1:
            continue
        for j in range(i, len(TABELA)-1):
            dzielniki2 = NWD(TABELA[j], TABELA[j+1])
            if dzielniki2 == dzielniki:
                licz_dlugosc += 1
            else:
                if licz_dlugosc > DLUGOSC:
                    DLUGOSC = licz_dlugosc
                    LICZBA_PIERWSZA = l1
                    DZIELNIK = dzielniki
                break
    print(f"Dzielnik {DZIELNIK}\nLiczba pierwsza: {LICZBA_PIERWSZA}\nDługość {DLUGOSC}")



# zad_1()
# zad_2()
zad_3()