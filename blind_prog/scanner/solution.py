from math import log2, ceil

upper = list(map(int, input().split()))

attempts = sum([ceil(log2(i)) for i in upper]) + 1
count = 0

lower = [1, 1, 1]

middle = upper[:]

for i in range(3):
    while upper[i] > lower[i]:
        middle[i] = (upper[i] + lower[i]) // 2
        print("?", ' '.join((map(str, lower))), ' '.join((map(str, middle))))
        count += 1
        if (input() == "found"):
            upper[i] = middle[i]
        else:
            lower[i] = middle[i] + 1
        middle[i] = (upper[i] + lower[i]) // 2

while count < attempts - 1:
    print("? 1 1 1 1 1 1")
    count += 1
    input()

print("!", ' '.join((map(str, lower))))
