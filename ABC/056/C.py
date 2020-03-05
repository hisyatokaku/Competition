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

cumsum = [0 for _ in range(10**5)]
for i in range(1, 10**5):
    cumsum[i] = cumsum[i-1] + i

for i, c in enumerate(cumsum[:100]):
    print(i, c)

def solve1(X):
    ok = 1
    for i, c in enumerate(cumsum):
        if i == X:
            ok = i
            break
        if X - c > i:
            ok = (X - c)
        else:
            break
    return ok


def main():
    X = I()
    s1 = solve1(X)
    print(s1)
main()

