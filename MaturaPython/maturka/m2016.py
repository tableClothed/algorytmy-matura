def szyfruj_pd1(slowo, klucz):
    klucz = klucz % 26
    nowe_slowo = ''
    for litera in slowo:
        n = ord(litera) + klucz
        # print(n, " ", ord(litera))
        if n > 90:
            n -= 26
        nowe_slowo += chr(n)
    # print(nowe_slowo)
    return nowe_slowo


def szyfruj_pd3(slowo, klucz):
    klucz = klucz % 25
    nowe_slowo = ''
    for litera in slowo:
        n = ord(litera) + klucz
        # print(n, " ", ord(litera))
        if n > 90:
            n -= 26
        nowe_slowo += chr(n)
    # print(nowe_slowo)
    return nowe_slowo


def rozszyfruj_pd2(slowo, klucz):
    klucz = klucz % 26
    nowe_slowo = ''
    for litera in slowo:
        n = ord(litera) - klucz
        # print(n, " ", ord(litera))
        if n < 65:
            n += 26
        nowe_slowo += chr(n)
    # print(nowe_slowo)
    return nowe_slowo


def rozszyfruj_pd3(slowo, klucz):
    klucz = klucz % 25
    nowe_slowo = ''
    for litera in slowo:
        n = ord(litera) - klucz
        # print(n, " ", ord(litera))
        if n < 65:
            n += 26
        nowe_slowo += chr(n)
    # print(nowe_slowo)
    return nowe_slowo


def znajdz_klucz(org, szyfr):
    a, b = ord(org[0]), ord(szyfr[0])
    if a > b:
        klucz = 26 - (a - b)
    else:
        klucz = b - a
    # print(klucz)
    return klucz


def pd_1(f):
    for line in f:
        line = line.rstrip()
        print(line, " ", szyfruj_pd1(line, 107))


def pd_2(f):
    for line in f:
        tab = line.rstrip().split(" ")
        if len(tab) < 2:
            break
        szyfr, key = tab[0], int(tab[1])
        print(rozszyfruj_pd2(szyfr, key), " ", szyfr)


def pd_3(f):
    for line in f:
        tab = line.rstrip().split()
        if len(tab) != 2:
            print(tab[0], " ")
            break
        org, szyfr = tab[0].rstrip(), tab[1].rstrip()
        klucz = znajdz_klucz(org, szyfr)
        r = rozszyfruj_pd3(szyfr, klucz)
        w = szyfruj_pd3(org, klucz)
        # print(org, " ", szyfr, " ", r)
        if r != org and w != org:
            print(org, " ")


f = open("mat/dane_6_2.txt", "r")
pd_2(f)
f.close()
