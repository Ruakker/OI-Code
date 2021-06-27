import random
import os
import sys

save = sys.stdout


def gen():
    a = random.randint(0, 114514)
    b = random.randint(0, 114514)
    print("{} {}".format(a, b))


while True:
    # os.system("gen.exe > data.in")
    sys.stdout = open('data.in', 'w+')
    gen()
    sys.stdout = save
    os.system("1.exe < data.in > 1.out")
    os.system("std.exe < data.in > std.out")
    if os.system("fc 1.out std.out"):
        os.system("pause")
        exit()

sys.stdout.close()