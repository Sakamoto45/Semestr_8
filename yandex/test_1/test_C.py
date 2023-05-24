import sys
n, m = list(map(int, input().split()))

better = 0
score_v = [0] * n

score_d = {0: n-1}


for game in range(m):
    a, b = list(map(int, sys.stdin.readline().split()))
    diff = a-b
    p = list(map(int, sys.stdin.readline().split()))

    if diff != 0:
        for i in range(10):
            if i == 5:
                diff = -diff
            if p[i] == 0:
                if diff > 0:
                    for j in range(diff):
                        score_v[0] += 1
                        better -= score_d.get(score_v[0], 0)
                else:
                    for j in range(-diff):
                        better += score_d.get(score_v[0], 0)
                        score_v[0] -= 1
            else:
                old_score = score_v[p[i]]
                score_v[p[i]] += diff
                new_score = score_v[p[i]]

                score_d[old_score] -= 1
                score_d[new_score] = 1 + score_d.get(new_score, 0)

                if old_score <= score_v[0] and new_score > score_v[0]:
                    better += 1
                elif old_score > score_v[0] and new_score <= score_v[0]:
                    better -= 1

    print(better)
