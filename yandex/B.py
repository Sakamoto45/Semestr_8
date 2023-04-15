def solve(a):
    # key= sum from 0 to value-1
    sums = {0: 0}

    pref_sum = 0
    for i in range(n):
        pref_sum += a[i]

        if (pref_sum - x) in sums:
            if sums.get(pref_sum - x) % 2 == 1:
                print("YES")
                return ()

        if (pref_sum + x) in sums:
            if sums.get(pref_sum + x) % 2 == 0:
                print("YES")
                return ()

        sums[pref_sum] = i+1
    print("NO")


n, x = list(map(int, input().split()))
t = list(map(int, input().split()))

solve([t[i] if i % 2 else -t[i] for i in range(n)])
