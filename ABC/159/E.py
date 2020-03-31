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
    g = []
    for _ in range(H):
        g.append(LI())
    R, C = H, W
    s2d = [[0 for _ in range(R+1)] for __ in range(C+1)]
    for r in range(R):
        for c in range(C):
            s2d[r+1][c+1] = s2d[r][c+1] + s2d[r+1][c] - s2d[r][c] + G[r][c]

    def query_cs2d(s, x1, x2, y1, y2):
        if x2 < x1:
            x1, x2 = x2, x1
        if y2 < y1:
            y1, y2 = y2, y1
        return s[x2][y2] - s[x1][y2] - s[x2][y1] + s[x1][y1]

    for i in range(H-1):
        for j in range(H-1):
            if (i >> j) & 1:
                cache = 0
                for r in range(R):
                    for c in range(C):
                        if r == j+1:
                            s2d[1 + j+1][1 + c] -= s2d[1+j][1+c]
                            cache = s2d[1+j][1+c]
                        else:
                            s2d[1 + j+1][1 + c] -= cache
                for r in range(R):
                    for c in range(C):
                        if r == j + 1:
                            s2d[r][c] = k

main()

