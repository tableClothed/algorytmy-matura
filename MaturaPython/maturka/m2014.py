def pd_a(f):
    count = 0
    for i in f:
        i = str(i).rstrip()
        a = ord(i[0])
        b = ord(i[-1])
        suma = int(a) + int(b)
        if liczba_pierwsza(suma):
            count += 1
    print("A: Jest " + str(count) + " liczb pierwszych")


def liczba_pierwsza(x):
    for i in range(2, round(x/2.0)):
        if x % i == 0:
            return False
    return True


def pd_b(f):
    count = 0
    for i in f:
        if czy_rosnacy(i):
            # print(i.rstrip())
            count += 1

    print("B: Jest " + str(count) + " liczb rosnących")


def czy_rosnacy(x):
    prev = 0
    x = x.rstrip()
    for i in x:
        ascii_ = ord(i)
        if ascii_ >= prev:
            prev = ascii_
        else:
            return False
    return True


def pd_c(f):
    napisy = []
    for i in f:
        if i not in napisy:
            napisy.append(i)
        else:
            print(i)


file = open("mat/NAPIS.txt")
pd_c(file)
file.close()