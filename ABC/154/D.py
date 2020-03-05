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

def ki(p):
    return (p + 1) / 2

def main():
    N, K = LI()
    p = LI()
    p = [ki(x) for x in p]
    cursum = sum(p[:K])
    ans = cursum
    i = K
    for i in range(K, N):
        cursum -= p[i-K]
        cursum += p[i]
        ans = max(cursum, ans)
    print(ans)
main()
