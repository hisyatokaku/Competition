import math,string,itertools,fractions,heapq,collections,re,array,bisect,sys,random,time,copy,functools
from collections import deque

sys.setrecursionlimit(10**7)
inf = 10**20
mod = 10**9 + 7

DR = [1, -1, 0, 0]
DC = [0, 0, 1, -1]

def LI(): return [int(x) for x in sys.stdin.readline().split()]
def LI_(): return [int(x)-1 for x in sys.stdin.readline().split()]
def LF(): return [float(x) for x in sys.stdin.readline().split()]
def LS(): return sys.stdin.readline().split()
def I(): return int(sys.stdin.readline())
def F(): return float(sys.stdin.readline())
def S(): return input()
     
def diff(p1, p2):
    return abs(p1[0] - p2[0]) + abs(p1[1] - p2[1])

def main():
    H, W, D = LI()
    A = []
    for _ in range(H):
        A.append(LI())
    Q = I()
    LR = []
    for _ in range(Q):
        LR.append(LI())
    num2point = [0 for _ in range(90001)]
    for r in range(H):
        for c in range(W):
            num = A[r][c]
            point = (r, c)
            num2point[num] = point
    num2mp = [0 for _ in range(90001)]

    for ix, p1 in enumerate(num2point):
        if not isinstance(p1, tuple) or ix <= D:
            continue
        p2 = num2point[ix - D]
        num2mp[ix] = num2mp[ix-D] + diff(p1, p2)

    for lr in LR:
        l = lr[0]
        r = lr[1]
        print(num2mp[r] - num2mp[l])
main()

