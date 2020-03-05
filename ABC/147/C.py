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

def countSetBits(n): 
    count = 0
    while (n): 
        count += n & 1
        n >>= 1
    return count 

def main():
    N = I()
    mat = [[-1 for __ in range(N)] for _ in range(N)]
    for i, _ in enumerate(range(N)):
        A = I()
        for __ in range(A):
            targ, b = LI()
            mat[i][targ - 1] = b
    ans = 0
    for bit in range(1 << N):
        truth = [-1 for _ in range(N)]
        err = False
        for i in range(N):
            honest_man = (bit & (1<<i))
            if honest_man:
                for j in range(len(mat[i])):
                    con = mat[i][j]
                    targ_ix = j
                    if con != -1:
                        if (bit >> targ_ix & 1) != con:
                            err = True
                        truth[targ_ix] = con
        if not err:
            ans = max(ans, countSetBits(bit))
    print(ans)
main()

