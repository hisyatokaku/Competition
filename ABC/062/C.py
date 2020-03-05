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

def solve(H, W):
    even = False
    ansmin = inf
    if W % 2 == 0:
        even = True
    for height in range(1, H):
        s1 = height * W
        if even:
            s2 = W * (H - height) // 2
            s3 = s2
            if s1 <= s2:
                s, m, l = s1, s2, s3
            else:
                s, m, l = s2, s3, s1
        else:
            s2 = (W - 1) * (H - height) // 2
            s3 = (W + 1) * (H - height) // 2
            if s1 <= s2 <= s3:
                s, m, l = s1, s2, s3
            elif s2 <= s3 <= s1:
                s, m, l = s2, s3, s1
            elif s2 <= s1 <= s3:
                s, m, l = s2, s1, s3
        ansmin = min(ansmin, l - s)
    return ansmin

def main():
    H, W = LI()
    if H % 3 == 0 or W % 3 == 0:
        print(0)
        return
    else:
        a1 = solve(H, W)
        a2 = solve(W, H)
        print(min(a1, a2))
        return

main()

