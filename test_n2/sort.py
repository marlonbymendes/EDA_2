import sys

arraySize = int(raw_input())
array = []

for i in range(0, arraySize):
    array.append(int(raw_input()))

array.sort()

print(arraySize)
for i in array:
    print(i)
