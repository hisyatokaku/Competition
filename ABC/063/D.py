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
    N, A, B = LI()
    cnt = 0
    if N == 1:
        cnt = N // A
        if N % A != 0:
            cnt += 1
        print(cnt)
        return

    H = []
    for _ in range(N):
        H.append(I())
    H = sorted(H)[::-1]
    h1, h2 = H[0], H[1]

    if h1 // A >= h2 // B:
        cnt = h1 // A
        if h1 % A != 0:
            cnt += 1
        print(cnt)
        return
    M = (h1 - h2) // (A - B)
    _h1 = h1 - M * A
    _h2 = h2 - M * B
    cnt += 2 * (_h1 // (A + B))

    __h1 = _h1 - max(1, (_h1 // (A+B))) * (A + B)
    __h2 = _h2 - max(1, (_h2 // (A+B))) * (A + B)

    if __h1 > 0:
        __h1 -= A
        __h2 -= B
        cnt += 1

    if __h1 > 0 or __h2 > 0:
        cnt += 1

    print(cnt)


main()

