n = int(input())

l = 0
w = 0
for c in range(9, 1, -1):
    if n % c == 0:
        l = n // c
        w = c
        break
if w != 0:
    print(l)
    print(' '.join([str(w) for i in range(0, l)]))
else:
    print(n//9 + 1)
    print(' '.join(['9' for _ in range(0, n//9)])) + ' ' + str(n % 9)
