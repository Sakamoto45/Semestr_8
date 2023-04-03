#!/usr/local/bin/python3.7
import sys


class Verdict:
    OK = 0
    WA = 1
    PE = 2
    FAIL = 10


try:
    with open(sys.argv[2], "r") as output_file:
        tries = int(output_file.read())

    with open(sys.argv[3], "r") as answer_file:
        max_tries = int(answer_file.read())

    if tries > max_tries:
        print("Limit exceeded: used %s attempts, max = %s" %
              (tries, max_tries), file=sys.stderr)
        sys.exit(Verdict.WA)

    print("Used %s attempts of %s" % (tries, max_tries), file=sys.stderr)
    sys.exit(Verdict.OK)
except Exception:
    sys.exit(Verdict.FAIL)
