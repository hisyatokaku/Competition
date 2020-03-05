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


def can_buy(A, B, X, m):
    return A * m + B * len(str(m)) <= X

def main():
    A, B, X = LI()
    if not can_buy(A, B, X, 1):
        print(0)
        return
    ok = 0
    ng = 10**9 + 1
    while ng - ok > 1:
        m = (ng + ok) // 2
        if can_buy(A, B, X, m):
            ok = m
        else:
            ng = m
    print(ok)

main()

