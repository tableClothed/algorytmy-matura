liczby = []
with open("mat/liczby19.txt", "r") as f:
    for line in f:
        line = line.rsplit()[0]
        liczby.append(int(line))

# ZAD 1


def czy_potega_3(liczba):
    while liczba > 1:
        if liczba % 3 != 0:
            break
        liczba /= 3
    if liczba == 1:
        return True
    else: return False


for liczba in liczby:
    if (czy_potega_3(liczba)):
        print(liczba)

# ZAD 2

def silnia(liczba):
    s = 1
    for i in range(2, liczba+1):
        s *= i
    return s

for liczba in liczby:
    l = str(liczba)
    suma = 0
    for s in l:
        suma += silnia(int(s))
    if suma == liczba:
        print(liczba)


# ZAD 3

def NWD(a, b):
    # if b > a:
    #     a, b = b, a
    while b > 0:
        a, b = b, a % b
    return a


PIERWSZA, DLUGOSC, DZIELNIK = 0, 0, 0
for i in range(len(liczby)-1):
    dlugosc = 1
    pierwsza = liczby[i]
    dz = liczby[i]
    for j in range(i+1, len(liczby)):
        dzielnik = NWD(dz, liczby[j])
        if dzielnik != 1:
            dlugosc += 1
            dz = dzielnik
        else:
            if dlugosc > DLUGOSC:
                DLUGOSC = dlugosc
                PIERWSZA = pierwsza
                DZIELNIK = dz
            break

print(PIERWSZA, DLUGOSC, DZIELNIK)