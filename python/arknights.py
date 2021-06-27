#!/bin/python

import random

p = 0.02


def lottery() -> bool:
    if random.random() <= p:
        return True
    else:
        return False


ans = [0] * 200

for i in range(1, 100000):
    cnt = 1
    p = 0.02
    while not lottery():
        cnt += 1
        if cnt > 50:
            p += 0.02
    ans[cnt] += 1

tot = 0
tot2 = 0

for i in range(1, 100):
    tot += ans[i] / 1000.
    tot2 += ans[i] / 1000. / 100. * i
    print("抽到第 {} 发出六星的概率: {:.2f}".format(i, tot))

print("期望次数: {:.2f}".format(tot2))
