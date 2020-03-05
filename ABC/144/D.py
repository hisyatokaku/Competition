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

def tan(deg):
    rad = deg * math.pi / 180.
    return math.tan(rad)

def calcDiff(a, b, angle, x):
    if tan(angle) > b / a:
        res = a*b*b/(2.* tan(angle))
    else:
        res = a*a*b - a*a*a*tan(angle) / 2.
    return res - x

def main():
    a, b, x = LI()
    ok = 0
    ng = 90
    diff = calcDiff(a, b, 0, x)
    while diff > 10**(-6) or diff < 0:
        m = (ok + ng) / 2.
        diff = calcDiff(a, b, m, x)
        if diff < 0:
            ng = m
        else:
            ok = m
    print(ok)

main()

