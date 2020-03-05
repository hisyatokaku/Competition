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
     
def main():
    N = I()
    X, Y, H = [], [], []
    for _ in range(N):
        x, y, h = LI()
        X.append(x)
        Y.append(y)
        H.append(h)
    def f(x, Cx, y, Cy, h):
        return h + abs(x - Cx) + abs(y - Cy)

    for cx in range(101):
        for cy in range(101):
            H_set = set()
            for x, y, h in zip(X, Y, H):
                if h == 0:
                    continue
                cur_h = f(x, cx, y, cy, h)
                H_set.add(cur_h)
            if len(H_set) == 1:
                print(cx, cy, cur_h)
                return

main()

