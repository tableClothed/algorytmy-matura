def pd_1(f):
    count = 0
    for line in f:
        line = line.rstrip()
        count_0 = 0
        count_1 = 0
        # print(line)
        for char_ in line:
            if char_ == '0':
                count_0 += 1
            elif char_ == '1':
                count_1 += 1

        if count_0 > count_1:
            count += 1

        # print(count_0, " ", count_1)

    print("4.1. Jest ", str(count), " takich liczb")


def pd_2(f):
    podzielne_2 = 0
    podzielne_8 = 0
    for line in f:
        line.rstrip()
        number = int(line)

        if number % 2 == 0:
            podzielne_2 += 1

        if number % 8 == 0:
            podzielne_8 += 1

    print("4.2. Jest ", str(podzielne_2), " liczb podzilenych przez 2 i ", str(podzielne_8), " liczb podzielnych przez 8")


def pd_3():
    min = 10 ** 6
    max = 0
    min_id = 0
    max_id = 0
    with open("mat/liczby.txt") as f:
        for num, line in enumerate(f, 1):
            line.rstrip()
            number = int(line, 2)
            if number > max:
                # print(number)
                max = number
                max_id = num
            if number < min:
                # print(number)
                min = number
                min_id = num
    print("4.3. Najwieksza liczba o id: ", max_id, ": \n", bin(max)[2:], "\nNajmniejsza liczba o id: ", min_id, "\n", bin(min)[2:])


file = open("mat/liczby.txt", "r")
# pd_1(file)
# pd_2(file)
pd_3()
file.close()