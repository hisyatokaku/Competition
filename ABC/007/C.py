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

def bfs():
    R, C = LI()
    srow, scol = LI_()
    grow, gcol = LI_()
 
    c = []
    visited = [[0 for _ in range(C)] for __ in range(R)]
    for _ in range(R):
        c.append(S())
    q = deque() 
    q.append((srow, scol, 0))
    while q:
        crow, ccol, cur_step = q.popleft()
        if crow==grow and ccol == gcol:
            return cur_step
        for dr, dc in zip(DR, DC):
            nrow, ncol = crow+dr, ccol+dc
            if not (0 <= nrow < R and 0 <= ncol < C):
                continue
            if c[nrow][ncol] == '#':
                continue
            if visited[nrow][ncol]:
                continue
            q.append((nrow, ncol, cur_step + 1))
            visited[nrow][ncol] = 1
    return -1

def main():
    ans = bfs()
    print(ans)

main()
