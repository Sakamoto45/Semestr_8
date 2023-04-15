import random
import time
import sys

b = list(map(lambda x: int(x, 2), input().split()))


dec_file = open("flags_output.txt", "w")
for seed in range(1428278400, 1428364799):
    random.seed(seed)
    decrypted = ""
    for bt in b:
        rand_shift = random.randint(0, 0x10)
        decrypted += chr(bt-rand_shift)
    dec_file.write(decrypted)
    dec_file.write("\n")

dec_file.close()

# print(list(map(chr, b)))
