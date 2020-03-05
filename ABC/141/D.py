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
    N, M = LI()
    A = LI()
    heap = heapq._heapify_max(A)
    total = sum(A)
    for _ in range(M):
        largest = heap._heappop_max(heap)
        discount = (largest + 1) // 2
        total -= discount
        new_element = largest - discount
        A.append(new_element)
        heap = heapq._heapify_max(A)
    print(total)
'''
def main():
    N, M = LI()
    A = LI()
    total = sum(A)
    discount = []
    for a in A:
        while a > 0:
            disc = (a+1)//2
            discount.append(disc)
            a -= disc
    discount = sorted(discount)[::-1]
    discount = discount[:M]
    print(total - sum(discount))
'''
main()

