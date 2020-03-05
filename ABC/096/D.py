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
     
n = 55555
prime = [True] * (n + 1)
prime[1] = False
max_range = int(math.sqrt(n)) + 1

for i in range(2, n + 1):
    if not prime[i]:
        continue
    if prime[i]:
        num = i + i
        while num < n:
            prime[num] = False
            num += i
primes = []
for i in range(1, 55556):
    if prime[i]:
        primes.append(i)
print(primes)
def main():
    pass

main()

