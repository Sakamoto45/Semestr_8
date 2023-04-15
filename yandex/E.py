def solve():
    n = int(input())
    f = [bool(int(i)) for i in input()]
    s = [bool(int(i)) for i in input()]
    r = sum([f[i] ^ s[i] for i in range(n)])
    if r != n and r != 0:
        print("NO")
        return ()
    print("YES")
    requests = []
    for i in range(n):
        if f[i]:
            requests.append(str(i+1)+" "+str(i+1))

    if ((len(requests) % 2) ^ f[0] ^ s[0]):
        requests.append(str(1)+" "+str(1))
        requests.append(str(2)+" "+str(n))
        requests.append(str(1)+" "+str(n))
    print(len(requests))
    for i in requests:
        print(i)


t = int(input())
for i in range(t):
    solve()
