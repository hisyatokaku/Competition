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
    

N, K = LI()
t = []
for _ in range(N):
    T = LI()
    t.append(T)
n, k = len(T), len(T[0])


def xor(nums):
    ans = nums[0] 
    for n in nums[1:]:
        ans = ans ^ n
    return ans

def has_bug(row, cur_vals, T):
    if row == n:
        return xor(cur_vals) == 0
    for i in range(k):
        if has_bug(row+1, cur_vals + [T[row][i]], T):
            return True
    return False

def main():
    ans = "Nothing"
    if has_bug(0, [], t):
        ans = "Found"
    print(ans) 

main()

