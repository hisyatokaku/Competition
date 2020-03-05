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
    H, W, K = LI()
    dp = [[[[0, 0] for _ in range(8)] for __ in range(8)] for ___ in range(101)]
    dp[0][1][0] = [1, 0]
    dp[0][0][0] = [1, 0]
    for t in range(1, H+1):
        for i in range(min(t, W)):
            for j in range(max(i-1, 0), min(i+1, W-1) + 1):
                # import pdb
                # pdb.set_trace()
                for k in range(max(i-1, 0), min(i+1, W-1) + 1):
                    cnt = dp[k][i][t-1][0]
                    extra = dp[k][i][t-1][1]
                    cur_extra = max(0, W - 2 - abs(j-i))
                    if min(i, j) == 0 or max(i, j) == W-1:
                        cur_extra = max(0, W - 1 - abs(j-1))
                    if extra == 0:
                        next_extra = cur_extra
                    else:
                        next_extra = extra * cur_extra
                    dp[i][j][t][0] += cnt
                    dp[i][j][t][1] += next_extra
    ans = 0
    for i in range(W):
        ans += sum(dp[i][K-1][H])
    print(ans)
main()

