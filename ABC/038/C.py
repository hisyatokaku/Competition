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
    A = LI()
    l = 0
    r = 1
    cur_cnt = 0
    cnt = 0
    while r < N:
        if A[r-1] < A[r]:
            cur_cnt = r - l + 1

            r += 1
        else:
            cnt += ((cur_cnt) * (cur_cnt - 1) // 2)
            cur_cnt = 0
            l = r
            r = l + 1
    cnt += ((cur_cnt) * (cur_cnt - 1) // 2)
    print(cnt + N)


main()

