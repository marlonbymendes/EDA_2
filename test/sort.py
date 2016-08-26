import sys

array = []
for line in sys.stdin:
    array.append(int(line))
array.sort()
for i in array:
    print(i)
