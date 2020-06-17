# SHIZAAA

x1 = ord("A")
x2 = ord("Z")
przedzial = (x2 - x1)

def zad1():
    DANE1 = []
    with open("dane_6_1.txt", "r") as f:
        DANE1 = f.readlines()
    DANE1 = [i.replace("\n", "") for i in DANE1]


    print(przedzial)
    klucz = 107 % (przedzial+1)
    print(klucz)

    NOWE_DANE1 = []
    for slowo in DANE1:
        nowe_slowo = ""
        for litera in slowo:
            wartosc = ord(litera)
            wartosc += klucz
            if wartosc > x2:
                x = wartosc - x2
                wartosc = x1 + x
            nowe_slowo += chr(wartosc)
        NOWE_DANE1.append(nowe_slowo)



def zad_2():
    DANE, KLUCZE = [], []
    with open("dane_6_2.txt", "r") as f:
        for line in f:
            line, klucz = line.replace("\n", "").split(" ")
            try:
                KLUCZE.append(int(klucz))
                DANE.append(line)
            except: continue

    NOWE_DANE = []
    for i in range(len(DANE)):
        klucz = KLUCZE[i] % (przedzial+1)
        line = DANE[i]
        nowe_slowo = ""
        for litera in line:
            wartosc = ord(litera)
            wartosc -= klucz
            if wartosc < x1:
                x = x1 - wartosc - 1
                wartosc = x2 - x
            nowe_slowo += chr(wartosc)
        NOWE_DANE.append(nowe_slowo)
    print(NOWE_DANE)
    print(DANE)


def znajdz_klucz(slowo, szyfr):
    litera_slowo = ord(slowo[0])
    litera_szyfr = ord(szyfr[0])
    if litera_slowo > litera_szyfr:
        x = x2 - litera_slowo
        w = litera_szyfr - x1 + x + 1
    else:
        w = litera_szyfr - litera_slowo
    return w


def szyfruj(slowo, klucz):
    nowe_slowo = ""
    for litera in slowo:
        wartosc = ord(litera)
        wartosc += klucz
        if wartosc > x2:
            x = wartosc - x2 -1
            wartosc = x1 + x
        nowe_slowo += chr(wartosc)
    return nowe_slowo


def zad_3():
    DANE, SZYFR = [], []
    with open("dane_6_3.txt", "r") as f:
        for line in f:
            a, b = line.replace("\n", "").split(" ")
            DANE.append(a)
            SZYFR.append(b)

    NIEZGODNE = []
    for i in range(len(DANE)):
        slowo = DANE[i]
        szyfr = SZYFR[i]
        klucz = znajdz_klucz(slowo, szyfr)
        szyfruj2 = szyfruj(slowo, klucz)
        if szyfr != szyfruj2:
            NIEZGODNE.append(slowo)
    print(NIEZGODNE)
    with open("wynik6_3.txt", "w") as f:
        for i in range(len(NIEZGODNE)):
            f.write(NIEZGODNE[i] + "\n")

zad_3()