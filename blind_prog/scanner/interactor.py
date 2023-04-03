#!/usr/local/bin/python3.7
import sys


class Verdict:
    OK = 0
    WA = 1
    PE = 2
    FAIL = 10


def calculate(attempt, answer):
    flag = attempt[0] == '!'
    attempt = list(map(int, attempt[1:]))
    answer = list(map(int, answer))
    if flag:
        if attempt == answer:
            result = 'ok'
        else:
            result = 'wa'
    elif all(attempt[i] <= answer[i] <= attempt[i+3] for i in range(3)):
        result = 'found'
    else:
        result = 'not found'
    return result


def isvalid(attempt):
    if attempt[0] == '?' and len(attempt) == 7 and all(i.isdigit() for i in attempt[1:]):
        return True
    if attempt[0] == '!' and len(attempt) == 4 and all(i.isdigit() for i in attempt[1:]):
        return True
    return False


try:
    with open(sys.argv[1], "r") as input_file:
        size = input_file.readline().split()
        print(' '.join(size), flush=True)
        answer = input_file.readline().split()

    with open(sys.argv[2], "w") as output_file:
        tries = 0

        while True:
            tries += 1

            try:
                attempt = input().split()
            except EOFError:
                print("EOF from participant", file=sys.stderr)
                sys.exit(Verdict.PE)

            if not isvalid(attempt):
                print("Invalid attempt: %s" %
                      ' '.join(attempt), file=sys.stderr)
                sys.exit(Verdict.PE)

            result = calculate(attempt, answer)

            print(result, flush=True)

            if result == 'ok':
                print(tries, file=output_file)

                print("Found point: %s" % ' '.join(attempt), file=sys.stderr)
                sys.exit(Verdict.OK)
            if result == 'wa':
                print(tries, file=output_file)

                print("Mistaken guess: %s" %
                      ' '.join(attempt), file=sys.stderr)
                sys.exit(Verdict.WA)
except Exception as e:
    print(type(e), e, file=sys.stderr)
    sys.exit(Verdict.FAIL)
