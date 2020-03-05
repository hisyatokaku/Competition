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
    H, N = LI()
    A, B = [], []
    for _ in range(N):
        a, b = LI()
        A.append(a)
        B.append(b)
    dp = [[0 for _ in range(10001)] for __ in range(1001)]
    for col in range(1, 10001):
        dp[0][col] = inf
    for i in range(N):
        for j in range(H+1):
            if j - A[i] >= 0:
                dp[i+1][j] = min(dp[i][j], dp[i+1][j-A[i]] + B[i])
            else:
                dp[i+1][j] = min(dp[i][j], B[i])
    print(dp[N][H])
main()

