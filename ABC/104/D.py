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
    string = S()
    a_cumsum = [0 for _ in range(len(string) + 1)]
    c_cumsum_inv = [0 for _ in range(len(string) + 1)]
    hatena_cumsum = [0 for _ in range(len(string)+1)]
    hatena_cumsum_inv = [0 for _ in range(len(string)+1)]

    for i, c in enumerate(string):
        if c == 'A':
            a_cumsum[i+1] += 1
        if c == '?':
            hatena_cumsum[i+1] += 1

    for i, c in enumerate(string[::-1]):
        if c == 'C':
            c_cumsum_inv[i+1] += 1
        if c == '?':
            hatena_cumsum_inv[i+1] += 1

    hatena_cumsum_inv = hatena_cumsum_inv[::-1]
    c_cumsum_inv = c_cumsum_inv[::-1]

    cnt = 0
    for i, c in enumerate(string):
        if c == '?':
            cnt += ((a_cumsum[i] * c_cumsum_inv[i+1]) % mod)
    print(cnt)
main()

