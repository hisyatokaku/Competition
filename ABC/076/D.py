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
     

def should_sd(cur_t, cur_v, next_ix, T, V):
    for i in range(next_ix, len(T)):
        Vsup = V[i+1]
        rem_t = T[i] - cur_t
        if cur_v - Vsup >= rem_t:
            return True
    return False

def main():
    N = I()
    T = LI()
    V = LI()
    V.append(0)
    for i in range(N-1):
        T[i+1] += T[i]
    cur_t = 0
    cur_v = 0
    prev_v = 0
    ix = 0
    next_ix = 0
    area = 0
    while cur_t < T[-1]:
        if cur_t == T[next_ix]:
            next_ix += 1
        if should_sd(cur_t, cur_v, next_ix, T, V):
            prev_v = cur_v
            cur_v -= 0.5
        else:
            if cur_v < V[next_ix]:
                prev_v = cur_v
                cur_v += 0.5
            else:
                prev_v = cur_v
        # add menseki
        p = (prev_v + cur_v) * 0.5 / 2
        area += p
        cur_t += 0.5
    print(area)
main()

