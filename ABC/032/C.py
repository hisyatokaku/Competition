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
    A = []
    for _ in range(N):
        A.append(I())
    if 0 in A:
        print(N)
        return
    cur_mul = A[0]
    st = 0
    en = 0
    length = 0
    for en in range(N):
        cur_mul *= A[en]
        if cur_mul > K:
            cur_mul = cur_mul // A[st]
            st += 1
        else:
            length += 1
    print(length)

main()

