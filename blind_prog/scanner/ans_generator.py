from math import log2, ceil

size = list(map(int, input().split()))
print(sum([ceil(log2(i)) for i in size]) + 1)
