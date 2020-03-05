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
     

def deepest_path(G, v, par = -1):
    children = G[v]
    if len(children) == 0:
        return 0
    max_path = -1
    for next_v in children:
        if next_v == par:
            continue
        max_path = max(deepest_path(G, next_v, v), max_path)
    return 1 + max_path

def main():
    N, u, v = LI()
    u -= 1
    v -= 1
    G = [[] for __ in range(N)]
    for _ in range(N-1):
        a, b = LI_()
        G[a].append(b)
        G[b].append(a)
    cnt = deepest_path(G, v) - 1
    print(cnt)

main()

