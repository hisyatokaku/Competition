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

def fct(n):
    if n == 1:
        return 1
    return n * fct(n-1)

def main():
    N = I()
    pos = []
    ans = 0
    G = [[0 for __ in range(N)] for _ in range(N)]
    for _ in range(N):
        x, y = LF()
        pos.append((x, y))
    for i in range(N):
        x = pos[i][0]
        y = pos[i][1]
        for j in range(N):
            jx = pos[j][0]
            jy = pos[j][1]
            dist = math.sqrt((x - jx)**2 + (y - jy)**2)
            ans += dist * fct(N-1) 
    print(ans / fct(N))
main()

