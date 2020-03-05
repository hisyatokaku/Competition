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

def f(L):
    if L == 0:
        return 'P'
    return 'B' + f(L-1) + 'P' + f(L-1) + 'B'

def main():
    N, X = LI()
    cnt = 0
    for c in f(N)[::-1][:X]:
        if c == 'P':
            cnt += 1
    print(cnt)


main()

