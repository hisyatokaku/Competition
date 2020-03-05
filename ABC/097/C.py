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
    s = S()
    k = I()
    seen = set()
    min_k = []
    for i in range(len(s)):
        curS = s[i]
        for j in range(i, len(s)):
            if j > i:
                curS += s[j]
            if curS not in seen:
                seen.add(curS)
                if len(min_k) < k:
                    min_k.append(curS)
                else:
                    if curS < min_k[-1]:
                        min_k[-1] = curS
                min_k = sorted(min_k)
    print(min_k[-1])
main()
