import math,string,itertools,fractions,heapq,collections,re,array,bisect,sys,random,time,copy,functools
from collections import deque


from fractions import gcd

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
    
def lcm(x, y):
    return (x * y) // gcd(x, y)

def main():
    a,b,c,d = LI()
    c_d_gcd = lcm(c,d)
    s = b//c + b//d - b//c_d_gcd
    t = (a-1) // c + (a-1) // d - (a-1) // c_d_gcd
    print(b - a + 1 - (s-t))
main()

