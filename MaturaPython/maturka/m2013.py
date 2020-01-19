def pd_a(f):
    count = 0

    for i in f:
        i = str(i).rstrip()
        # print(i[0] + " " + i[1] + " " + i[-2])
        if i[0] == i[-1]:
            count += 1

    print("A: Linijek jest: " + str(count))


def pd_b(f):
    count = 0
    for i in f:
        i = str(i).rstrip()
        i = str(oct_to_dec(i))

        if i[0] == i[-1]:
            count += 1

    print("B: Linijek jest: " + str(count))


def oct_to_dec(x):
    y = str(x)
    suma = 0
    potega = 1
    y = y[::-1] # REVERSE
    for i in y:
        suma += pow(int(i), potega)
        potega += 1

    return suma


def pd_c(f):
    min = 100000
    max = 0
    count = 0
    for i in f:
        i = str(i).rstrip()
        if check_if_larger(i):
            count += 1
            if int(i) < min:
                min = int(i)
            if int(i) > max:
                max = int(i)

    print("C: Liczb: " + str(count) + ", MAX: " + str(max) + ", MIN: " + str(min))


def check_if_larger(x):
    y = str(x).rstrip()
    prev = 0
    for i in y[1:]:
        if int(i) >= prev:
            # print(i + " " + str(prev))
            prev = int(i)
        else:
            return False
    return True


file = open("mat/dane.txt", "r")
pd_a(file)
file.close()

file = open("mat/dane.txt", "r")
pd_b(file)
file.close()

file = open("mat/dane.txt", "r")
pd_c(file)
file.close()
