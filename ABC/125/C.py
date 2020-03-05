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
    gcd = fractions.gcd
    N = I()
    A = LI()
    left = [1] * N
    right = [1] * N
    left[0] = A[0]
    right[N-1] = A[N-1]
    ans = -1

    for i in range(1, N):
        left[i] = gcd(A[i], left[i-1])
    for j in range(N-2, -1, -1):
        right[j] = gcd(A[j], right[j+1])
    for i in range(N):
        if i-1<0:
            ans = max(ans, right[i+1])
            continue
        if i+1 >= N:
            ans = max(ans, left[i-1])
            continue
        ans = max(ans, gcd(left[i-1], right[i+1]))

    print(ans)

main()


'''

N = int(input())
S = list(input())

ans = 0
s_count = 0
if len(S) == 1:
    print(ans)
elif len(S) == 2:
    if S == ['#', '.']:
        print("1")
    else:
        print("0")
elif len(S) == 3:
    for i in range(len(S)-1):
        if S[i] == '#' and S[i+1] == '.':
            ans += 1
    print(ans)
            
else:
    for c in S[:-1]:
        if c=='#':
            s_count += 1
    for i in range(len(S)-3):
        if S[i:i+4] == ['.','#','.','.']:
            S[i:i+4] = ['.','.','.','.']
            
        elif S[i:i+4] == ['.','#','.','#']:
            S[i:i+4] = ['.','#','#','#']

        elif S[i:i+4] == ['#','#','.','.']:
            S[i:i+4] = ['#','#','#','.']

        elif S[i:i+4] == ['#','#','.','#']:
            S[i:i+4] = ['#','#','#','#']
        else:
            continue
        ans += 1

    print(min(s_count, ans, len(S)-s_count))
print(S)
'''
