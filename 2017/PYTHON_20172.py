PIKSELE = []
with open("dane.txt", "r") as f:
    for line in f:
        line = line.replace('\n', "")
        PIKSELE.append([int(i) for i in line.split(" ")])

PRZYKLAD = []
with open("przyklad.txt", "r") as f:
    for line in f:
        line = line.replace('\n', "")
        PRZYKLAD.append([int(i) for i in line.split(" ")])


def zad_1():
    max_, min_ = 0, PIKSELE[0][0]
    for line in PIKSELE:
        m = max(line)
        if m > max_:
            max_ = m
        m = min(line)
        if m < min_:
            min_ = m
    print(f"Najmniejsza wartosć: {min_},\nNajwiększa wartość: {max_}")


def zad_2():
    usun = 0
    for line in PIKSELE:
        for j in range(0, len(line)//2):
            if line[j] != line[-1-j]:
                usun += 1
                break
    print(F"Usun: {usun}")


def zad_3():
    kontastujace = 0
    for x in range(len(PIKSELE)):
        for y in range(320):
            if x != len(PIKSELE)-1:
                if abs(PIKSELE[x][y] - PIKSELE[x+1][y]) > 128:
                    kontastujace += 1
                    break
            if x != 0:
                if abs(PIKSELE[x][y] - PIKSELE[x-1][y]) > 128:
                    kontastujace += 1
                    break
            if y != len(PIKSELE[0])-1:
                if abs(PIKSELE[x][y+1] - PIKSELE[x][y]) > 128:
                    kontastujace += 1
                    break
            if y != 0:
                if abs(PIKSELE[x][y-1] - PIKSELE[x][y]) > 128:
                    kontastujace += 1
                    break
    print(f"Ilość liczb kontastujących: {kontastujace}")

zad_1()
zad_2()
zad_3()