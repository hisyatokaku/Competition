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

fac = [-1] * (10**7+1)
inv = [-1] * (10**7+1)
finv = [-1] * (10**7+1)

fac[0] = fac[1] = 1
inv[1] = 1
finv[0] = finv[1] = 1

def initNCMMod(limit):
    for i in range(2, limit):
        fac[i] = fac[i-1] * i % mod
        inv[i] = mod - inv[mod%i] * (mod // i) % mod
        finv[i] = finv[i-1] * inv[i] % mod

def NCMMod(n, k):
    if n < k:
        return 0
    if (n < 0 or k < 0):
        return 0
    return fac[n] * (finv[k] * finv[n-k] % mod) % mod

initNCMMod(100000)

def inv_fac(n):
    # inv[n!] = inv[n] * inv[n-1] * ... inv[1]
    if n == 1:
        return 1
    return inv[n] * inv_fac(n-1) % mod

def main():
    R, C = LI()
    X, Y = LI()
    D, L = LI()
    cnt = 0
    if D + L == X * Y:
        cnt += NCMMod(X*Y, D) % mod
    else:
        empty = R * C - D - L
        import pdb
        pdb.set_trace()
        cnt += fac[R*C] * inv_fac(D) * inv_fac(L) * inv_fac(empty)
        cnt %= mod
    x_margin = R - X + 1
    y_margin = C - Y + 1
    print((cnt * x_margin * y_margin) % mod)
main()

