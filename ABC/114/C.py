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
    s = S()
    N = len(s)
    dp = [[[0 for _ in 1<<3] for __ in range(2)] for _k in N+1]
    for i in range(N):
        for j in range(2):
            D = int(s[j])
            if j:
                end_d = 10
            else:
                end_d = D+1
            for d in range(1, end_d):
                for bit in range(1<<s):
                    for k in range(N):
                        mask = 1 << k
                        subbit = bit & mask
                        dp[i+1][j or int(d < D)][bit] += dp[i][1][subbit]



main()

