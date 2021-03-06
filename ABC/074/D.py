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
    G = []
    dp = []
    for _ in range(N):
        a = LI()
        G.append(a)
        dp.append(a)

    for i in range(N):
        for j in range(N):
            for k in range(N):
                if G[i][j] > G[i][k] + G[k][j]:
                    print(-1)
                    return

    for i in range(N):
        for j in range(N):
            for k in range(N):
                if j == k or k == i:
                    continue
                if dp[i][k] == inf or dp[i][j] == inf or dp[j][k] == inf:
                    continue
                if G[i][j] == G[i][k] + G[k][j]:
                    # i->jは要らない
                    dp[i][j] = inf
    cnt = 0
    for i in range(N):
        for j in range(N):
            if dp[i][j] < inf:
                cnt += dp[i][j]
    print(cnt // 2)
main()

