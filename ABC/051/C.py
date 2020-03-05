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
    sx, sy, tx, ty = LI()
    right = (tx - sx)
    up = (ty - sy)
    p1 = 'R' * right + 'U' * up
    p2 = 'L' * right + 'D' * up
    p3 = 'D' + 'R' * (right + 1) + 'U' * (up + 1) + 'L'
    p4 = 'U' + 'L' * (right + 1) + 'D' * (up + 1) + 'R'
    print(p1+p2+p3+p4)
main()

