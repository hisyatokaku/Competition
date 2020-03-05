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
    cumsum = [0 for _ in range(N+1)]
    for i in range(N):
        cumsum[i+1] = cumsum[i] + A[i]
    ans = 0
    print(cumsum)
    for i in range(N):
        print('a: ', A[i])
        print('cumsum: ', cumsum[i] - cumsum[0])
        ans += (A[i] ^ (cumsum[i] - cumsum[0])) % mod
    print(ans)
main()

