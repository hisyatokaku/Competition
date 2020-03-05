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

def count_miman(A, x):
    # return count of mul less than x
    # A: sorted
    cnt = 0
    N = len(A)
    pos = [a for a in A if a > 0]
    neg = [a for a in A if a < 0]
    for i in range(A):
        if A[i] < 0:
            ng = -1
            ok = len(A)
            # xがプラスのときにneg同士をかけたものも考慮しないといけない
            while ng + 1 < ok:
                c = (ng + ok) // 2
                if A[c] * A[i] < x:
                    ok = c
                else:
                    ng = c
            cnt += (len(A) - ok)
        elif A[i] == 0:
            if x > 0:
                cnt += (len(pos) + len(neg))
        else:
            pass
            


def main():
    N, K = LI()
    A = LI()
    A = sorted(A)
    ok = -10**9 - 1 # K未満
    ng = 10**9 + 1
    while l + 1 < r:
        m = (l - r) // 2 + r
        if count_miman(A, x) < K:
            ok = m
        else:
            ng = m
    print(m)

main()

