sygnaly_array = []
przyklad_array = []
with open("mat/sygnaly.txt", "r") as f:
    for line in f:
        sygnaly_array.append(list(line.rstrip()))

with open("mat/przyklad18.txt", "r") as f:
    for line in f:
        przyklad_array.append(list(line.rstrip()))


def pd_1():
    slowo = ""
    arr = sygnaly_array
    for i in range(39, len(arr), 40):
        sl = arr[i][9]
        slowo += sl
    print(f"Slowo: {slowo}")


def pd_2():
    arr = sygnaly_array
    najwieksze = ""
    for line in arr:
        slowa = []
        for letter in line:
            if letter not in slowa:
                slowa.append(letter)
            if len(slowa) > len(najwieksze):
                najwieksze = "".join(slowa)

    print(f"Najwieksze: {najwieksze} {len(najwieksze)}")


def pd_3():
    arr = sygnaly_array
    koncowa_array = []
    oddalone = True
    for line in arr:
        for i in range(len(line)-1):
            letterA = ord(line[i])
            letterB = ord(line[i+1])

            if abs(letterA - letterB) > 10:
                oddalone = False
                break

        if oddalone:
            koncowa_array.append(line)
        else:
            oddalone = True

    liter(koncowa_array)


def liter(array):
    slowo = ""
    ii = 0
    for i in array:
        for l in i:
            slowo += l
        print(str(ii) + " "+ slowo)
        slowo = ""
        ii += 1


# pd_1()
# pd_2()
# pd_3()
# liter(przyklad_array)