import bisect
import sys


n = int(input())
a = sorted(list(map(int, input().split())))
k = int(input())

rooms = dict()

for i in range(k):
    size, amount = list(map(int, input().split()))
    rooms[size] = amount + rooms.get(size, 0)

sizes = sorted(list(rooms))

for team in a:
    i = bisect.bisect_left(sizes, team)
    if i == len(sizes):
        print("No")
        sys.exit()
    rooms[sizes[i]] -= 1
    if rooms[sizes[i]] == 0:
        del rooms[sizes[i]]
        sizes.pop(i)


print("Yes")
