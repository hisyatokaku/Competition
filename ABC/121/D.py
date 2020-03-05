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
    digit = 1
    while n > 1:
        n = n >> 1
        digit += 1
    return digit

def bit_after_xor(groups, offset):
    if offset == 0:
        if groups % 2 == 1:
            return 0
        else:
            return 1
    else:
        if groups % 2 == 1:
            return 1
        else:
            return 0

def zeroXOR(n):
    # i桁目の1の個数を調べる
    digit = get_digit(n)
    ans = 0
    for i in range(digit):
        twos = 1 << i
        groups = (n + 1) // twos
        offset = (n + 1) % twos
        result_bit = bit_after_xor(groups, offset)
        print('i: ', i, ' twos: ', twos, ' groups: ', groups, ' offset: ', offset, ' result_bit: ', result_bit)
        ans += (result_bit << i)
    return ans

def main():
    A, B = LI()
    print(zeroXOR(A))
    print(zeroXOR(B))
    print(zeroXOR(B) ^ zeroXOR(A))

main()

