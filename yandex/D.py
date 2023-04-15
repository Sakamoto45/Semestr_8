# import random
from random import choices


def generate(m=10):
    a = choices(range(m-1), k=m)
    checked = [False] * m
    for i in range(m):
        if not checked[i]:
            if a[i] == i:
                a[i] = m-1
            checked[a[i]] = True
    return (m-sum(checked))


N = 10000000

sample = [generate() for i in range(N)]

print(sum(sample)/N)
