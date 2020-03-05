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

def lcm(a, b):
    gcd = fractions.gcd
    n_gcd = gcd(a, b)
    return a * b // n_gcd

def main():
    N = I()
    T = []
    for _ in range(N):
        T.append(I())
    n_lcm = lcm(T[0], T[0])
    for i in range(1, N):
        n_lcm = lcm(n_lcm, T[i])
    print(n_lcm)
main()

