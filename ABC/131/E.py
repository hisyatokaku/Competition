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
    N, K = LI()
    tot_M = (N-1)*N/2
    M = tot_M - K
    if M < N - 1:
        print(-1)
        return
    print(int(M))
    cnt = 0
    for ix in range(N-1):
        print("1 {}".format(ix+2))
        cnt += 1

    for ix in range(2, N+1):
        for jx in range(ix+1, N+1):
            if cnt >= M:
                return
            print("{} {}".format(ix, jx))
            cnt += 1
            
main()

