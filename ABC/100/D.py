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

def abssum(tup):
    cnt = 0
    for elem in tup:
        cnt += elem
    return cnt

def sum_tuple(tup1, tup2):
    li = []
    for i in range(len(tup1)):
        li.append(tup1[i] + tup2[i])
    return tuple(li)

def main():
    N, M = LI()
    cakes = []
    for _ in range(N):
        x, y, z = LI()
        cakes.append((x, y, z))

    dp = [[(0, 0, 0) for _ in range(M + 1)] for __ in range(N + 1)]

    for i in range(N):
        for j in range(min(M+1, i+2)):
            val_use_i = (0, 0, 0)
            if j - 1 >= 0:
                val_use_i = sum_tuple(dp[i][j-1], tuple(cakes[i]))
            val_no_use_i = dp[i][j]
            tot_val_use_i = abssum(val_use_i)
            tot_val_no_use_i = abssum(val_no_use_i)

            if tot_val_use_i < tot_val_no_use_i:
                dp[i+1][j] = val_no_use_i
            else:
                dp[i+1][j] = val_use_i
    # import pdb
    # pdb.set_trace()
    print(abssum(dp[N][M]))

main()

