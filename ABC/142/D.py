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

def integer_factorization(n):
    prime_count = collections.Counter()
    for i in range(2, int(math.sqrt(n)) + 2):
        while n % i == 0:
            n //= i
            prime_count[i] += 1
    if n > 1:
        prime_count[n] += 1
    return prime_count

prime = [True] * (10**6 + 2)
prime[1] = False
max_range = int(math.sqrt(10**6)) + 1

for i in range(2, 10**6 + 1):
    if not prime[i]:
        continue
    if prime[i]:
        num = i + i
        while num < max_range:
            prime[num] = False
            num += i

def main():
    gcd = fractions.gcd
    A, B = LI()
    m = gcd(A, B)
    cnt = 1
    cnt += len(integer_factorization(m))
    # for i in range(2, int(math.sqrt(m)) + 1):
    #     if m % i != 0:
    #         continue
    #     if prime[i]:
    #         cnt += 1
    print(cnt)
main()

