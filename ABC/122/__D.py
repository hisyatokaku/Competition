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
     
def get_digit(n):
    cnt = 1
    while n > 1:
        n = n >> 1
        cnt += 1
    return cnt

def calc_digit(n, is_one):
    if is_one == 0 and n % 2 == 0:
        ans = n//2
    elif is_one == 0 and n % 2 == 1:
        ans = (n-1)//2
    elif is_one == 1 and n % 2 == 0:
        ans = n // 2
    elif is_one == 1 and n % 2 == 1:
        ans = (n+1) // 2
    return ans % 2


def get_carry(n, is_one):
    if n % 2 == 0:
        return n // 2
    else:
        if is_one == 0:
            return (n-1)//2
        else:
            return (n+1)//2

def main():
    A, B = LI()
    diff = B - A
    cnt = 0
    carry = diff
    n = get_digit(diff)
    i = 0
    while carry:
        bit = (A >> i) & 1
        print('i: ', i)
        print('bit: ', bit)
        print('carry: ', carry)
        res_digit = calc_digit(carry, bit)
        carry = get_carry(carry, bit)
        cnt += (res_digit << i)
        print('res_digit: ', res_digit)
        print('new_carry: ', carry)
        print()
        i += 1
    print(cnt)

main()

