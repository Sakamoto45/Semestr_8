#!/usr/local/bin/python3.7
import sys


class Verdict:
    OK = 0
    WA = 1
    PE = 2
    FAIL = 10


try:
    size = input().split()
    answer = input().split()

    if len(size) != 3 or not all(i.isdigit() for i in size):
        sys.exit(Verdict.PE)
    if len(answer) != 3 or not all(i.isdigit() for i in answer):
        sys.exit(Verdict.PE)
    answer = list(map(int, answer))
    size = list(map(int, size))
    if any(answer[i] > size[i] for i in range(3)):
        sys.exit(Verdict.PE)
    if any(i > 1000000000 for i in size):
        sys.exit(Verdict.PE)
    sys.exit(Verdict.OK)

except Exception:
    print(Exception)
    sys.exit(Verdict.FAIL)
