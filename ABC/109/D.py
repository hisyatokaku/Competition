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

def hitofude(H, W):
    for row in range(H):
        for col in range(W):
            if row % 2 == 1:
                new_col = W - 1 - col
            else:
                new_col = col
            yield (row, new_col)


def main():
    H, W = LI()
    A = []
    for _ in range(H):
        a = LI()
        A.append(a)
    cur = list(hitofude(H, W))[:-1]
    nex = list(hitofude(H, W))[1:]
    ans = []
    for (cur_r, cur_c), (nex_r, nex_c) in zip(cur, nex):
        if A[cur_r][cur_c] % 2 == 0:
            pass
        else:
            A[cur_r][cur_c] -= 1
            A[nex_r][nex_c] += 1
            ans.append((cur_r + 1, cur_c + 1, nex_r + 1, nex_c + 1))
    print(len(ans))
    for a in ans:
        print(*a)

main()

