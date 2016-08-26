from random import randint

array = []
arraySize = 10 ** 3

UPPER = 2 ** 30 + 1
LOWER = UPPER * (-1)

for i in range(0, arraySize):
    nextNum = randint(LOWER, UPPER)
    array.append(nextNum)

for i in array:
    print(i)
