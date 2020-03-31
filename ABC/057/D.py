import math,string,itertools,fractions,heapq,collections,re,array,bisect,sys,random,time,copy,functools
from collections import deque, Counter

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

fac = [-1] * (10**2+1)

fac[0] = fac[1] = 1

def initNCM(limit):
    for i in range(2, limit):
        fac[i] = fac[i-1] * i

def NCM(n, r):
    return fac[n] / (fac[r] * fac[n-r])

initNCM(100)

def main():
    N, A, B = LI()
    v = sorted(LI())[::-1]
    cnt = Counter(v)
    selected = v[:A]
    print(sum(selected)/A)
    ans = 1
    used = 0
    for x in list(set(selected)):
        used += cnt[x]
    used -= cnt[selected[-1]]
    ans = 0
    if len(list(set(selected))) > 1:
        use_last = A - used
        ans += NCM(cnt[selected[-1]], use_last)
    else:
        for use_last in range(1, N+1):
            if not A <= used + use_last <= B:
                continue
            if use_last > cnt[selected[-1]]:
                continue
            ans += NCM(cnt[selected[-1]], use_last)
    print(int(ans))

main()

