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
    red = []
    blue = []
    for _ in range(N):
        x, y = LI()
        red.append((x, y))
    for _ in range(N):
        x, y = LI()
        blue.append((x, y))
    red = sorted(red, key=lambda x: x[0])
    blue = sorted(blue, key=lambda x: x[1])
    blue_used = set()
    cnt = 0
    for rx, ry in red:
        for i, (bx, by) in enumerate(blue):
            if i in blue_used:
                continue
            if bx <= rx or by <= ry:
                continue
            cnt += 1
            blue_used.add(i)
            break
    print(cnt)
main()

