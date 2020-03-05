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
    N, M = LI()
    jobsavailable = [[] for _ in range(10**5+1)]
    for _ in range(N):
        a, b = LI()
        if a > M:
            continue
        jobsavailable[M-a].append(b)
    cur_jobs = []
    cnt = 0
    for i in range(1, M+1):
        jobs = jobsavailable[M-i]
        for j in jobs:
            heapq.heappush(cur_jobs, -j)
        if cur_jobs != []:
            j = -heapq.heappop(cur_jobs)
            cnt += j
    print(cnt)

main()

