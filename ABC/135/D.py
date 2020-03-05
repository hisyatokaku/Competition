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
    dp = [[0 for _ in range(13)] for ___ in range(N)]
    # dp[i][j]: iまでみてあまりがjである数の個数
    for c in range(13):
        if s[0] == '?':
            for k in range(10):
                new_mod = k * (10**(N - 1)) % 13
                dp[0][new_mod] = 1
        else:
            new_mod = int(s[0]) * (10**(N-1)) % 13
            dp[0][new_mod] = 1
    for i in range(1, N):
        c = s[i]
        for j in range(0, 13):
            if c == '?':
                for k in range(10):
                    new_mod = j + int(k) * (10**(N - 1 - i))
                    new_mod %= 13
                    dp[i][new_mod] += dp[i-1][j]
            else:
                new_mod = j + int(c) * (10 ** (N - 1 - i))
                new_mod %= 13
                dp[i][new_mod] += dp[i-1][j]
            dp[i][new_mod] %= mod
    print(dp[N-1][5] % mod)

main()

