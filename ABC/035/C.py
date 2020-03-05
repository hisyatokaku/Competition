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
    N, Q = LI()
    koma = [0 for _ in range(N + 1)]
    for _ in range(Q):
        l, r = LI_()
        koma[l] += 1
        koma[r+1] -= 1
    for i in range(N):
        koma[i+1] += koma[i]
        koma[i] = koma[i] % 2
    ans = ''
    for i in range(N):
        if koma[i] % 2 == 0:
            ans += '0'
        else:
            ans += '1'
    print(ans)
main()

