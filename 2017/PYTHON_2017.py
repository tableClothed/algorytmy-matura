pixel_array = []
with open("mat/dane17.txt") as f:
    for line in f:
        x = line.rstrip().split(" ")
        x = list(map(int, x))
        pixel_array.append(x)


def pd_1():
    _max = 0
    _min = 255
    with open("mat/dane17.txt", "r") as f:
        for line in f:
            piksele = line.rstrip().split(" ")
            for piksel in piksele:
                piksel = int(piksel)
                if piksel > _max:
                    _max = piksel
                if piksel < _min:
                    _min = piksel
    print("min: ", str(_min), " , max: ", str(_max))


def pd_2():
    count = 0
    with open("mat/dane17.txt", "r") as f:
        for line in f:
            l = line.rstrip().split(" ")
            r = list(reversed(l))
            for i in range(320):
                if l[i] != r[i]:
                    count += 1
                    break
    print(f"Ilosc lini wynosi {count}")


def pd_3():
    array = []
    count = 0
    with open("mat/dane17.txt", "r") as f:
        for line in f:
            x = line.rstrip().split(" ")
            x = list(map(int, x))
            array.append(x)
            # print(f"{line}, {type(line)}")

    for index_linii in range(len(array)):  # wiersze
        for index_piksela_w_linii in range(200):  # piksele
            if sprawdz(array, index_piksela_w_linii, index_linii):
                count += 1
    print(f"Jest {count} takich pikselów")


def sprawdz(array, index_pixela, index_linii):
    roznica = 128
    print(f"{index_linii}, {index_pixela}, {array[index_pixela][index_linii]}")
    if index_pixela != 0:
        linia_lewo = abs(array[index_pixela][index_linii] - array[index_pixela - 1][index_linii]) > roznica
    if index_pixela != 199:
        linia_prawo = abs(array[index_pixela][index_linii] - array[index_pixela + 1][index_linii]) > roznica
    if index_linii != 0:
        linia_gora = abs(array[index_pixela][index_linii] - array[index_pixela][index_linii - 1]) > roznica
    if index_linii != len(array)-1:
        linia_dol = abs(array[index_pixela][index_linii] - array[index_pixela][index_linii + 1]) > roznica
    if index_linii == 0:
        if index_pixela == 0:
            if linia_prawo or linia_dol:
                return True
        elif index_pixela == 199:
            if linia_lewo or linia_dol:
                return True
        else:
            if linia_prawo or linia_prawo or linia_dol:
                return True
    elif index_linii == len(array) - 1:
        if index_pixela == 0:
            if linia_prawo or linia_gora:
                return True
        elif index_pixela == 199:
            if linia_lewo or linia_gora:
                return True
        else:
            if linia_prawo or linia_prawo or linia_gora:
                return True
    else:
        if index_pixela == 0:
            if linia_prawo or linia_gora or linia_dol:
                return True
        elif index_pixela == 199:
            if linia_lewo or linia_gora or linia_dol:
                return True
        else:
            if linia_dol or linia_gora or linia_prawo or linia_lewo:
                return True

    return False


def pd_4():
    dlugosc = 0
    for x in range(len(pixel_array)-1):
        count = 0
        for y in range(200):
            pixel = pixel_array[y][x]
            next_pixel = pixel_array[y][x+1]
            print(f"{pixel}, {next_pixel}")
            if pixel == next_pixel:
                count += 1
            else:
                if count > dlugosc:
                    dlugosc = count
                    count = 0
    print(f"Dlugosc {dlugosc}")


# pd_1()
# pd_2()
# pd_3()
pd_4()