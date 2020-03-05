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
    W = I()
    N, K = LI()
    a = []
    b = []
    dp = [[[0 for _ in range(K+1)] for __ in range(W+1)] for t in range(N+1)]

    for _ in range(N):
        _a, _b = LI()
        a.append(_a)
        b.append(_b)
    
    for row in range(N+1):
        for col in range(W+1):
            for k in range(K+1):
                dp[row][col][0] = 0
                dp[row][0][k] = 0
                dp[0][col][k] = 0
    for row in range(1, N+1):
        for col in range(1, W+1):
            for k in range(1, K+1):
                if col - a[row-1] >= 0:
                    dp[row][col][k] = max(dp[row-1][col][k], dp[row-1][col-a[row-1]][k-1] + b[row-1])
                else:
                    dp[row][col][k] = dp[row-1][col][k]
                #print('dp[{}][{}][{}]: {}'.format(row, col, k,dp[row][col][k]))
    print(dp[N][W][K])
main()

