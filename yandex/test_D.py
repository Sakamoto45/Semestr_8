import fileinput
import re
money = 10000
sum = 0


def time(day, hour, minute, second):
    return (second + 60 * (minute + 60*(hour + 24*(day-1))))


later = time(32, 0, 0, 0)

f = open("output.txt", "w")


for line in fileinput.input(files='input.txt'):
    year, month, day, hour, minute, second, value = list(
        map(int, re.split('-|:| ', line)))
    sum += value
    now = time(day, hour, minute, second) + 1
    # print(f'{money - sum / now * later:.2f}')
    f.write(f'{money - sum / now * later:.2f}\n')


f.close()
