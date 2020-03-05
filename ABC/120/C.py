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
     

def reverse_str(n):
    n = int(n)
    return str((1 - n) ** 2)

def main():
    s = S()
    dp = [(0, '') for _ in range(len(s)+1)]
    dp[0] = (1, s[0])
    for i in range(1, len(s)):
        prev_let = dp[i-1][1]
        prev_len = dp[i-1][0]
        if s[i] == prev_let:
            dp[i] = (prev_len + 1, s[i])
        elif prev_let == '':
            dp[i] = (prev_len + 1, s[i])
        else:
            if prev_len - 1 == 0:
                prev_let = ''
            else:
                prev_let = reverse_str(s[i])
            dp[i] = (prev_len - 1, prev_let)
    print(len(s) - dp[len(s)-1][0])
    '''
    dp = [[0 for _ in range(2)] for __ in range(len(s) + 1)]
    for i in range(1, len(s)+1):
        j = int(s[i-1])
        if j == 0:
            dp[i][0] = dp[i-1][0] + 1
            dp[i][1] = dp[i-1][1] - 1
        else:
            dp[i][0] = dp[i-1][1] + 1
            dp[i][1] = dp[i-1][0] - 1
    '''
    """
    if s[i-1] == str(j):
        dp[i][j] = (dp[i-1][j] + 1)
    else:
        dp[i][reverse(j)] = (dp[i-1][reverse(j)] - 1)
    """
main()

