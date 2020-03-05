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

def S(n):
    cnt = 0
    for c in str(n):
        cnt += int(c)
    return cnt

def calc_i_to_change(cand):
    '''
    299999
      ^   
    543210
    012345
    return 3
    '''
    l = sum(cand)
    n = int(''.join([str(x) for x in cand]))

    for i in range(len(cand))[::-1]:
        power = len(cand) - i
        k = 10 ** power
        if (n - k) - k * l <= 0:
            return len(cand) - 1 - power
    return -1

def main():
    # test = []
    # for i in range(1, 3000000):
    #     test.append((i, i/S(i)))
    #     # print('n: ', i, ' n/s(n): ', i/S(i))
    # test = sorted(test, key=lambda x:x[1])
    # cur_min = 0
    # for t in test:
    #     n, res = t
    #     if n < cur_min:
    #         continue
    #     cur_min = n
    #     print(t)
    K = I()
    num = 0
    n_digit = 1
    cand = [1]
    ans = []

    while K > 0:
        import pdb
        pdb.set_trace()

        i_to_change = calc_i_to_change(cand)
        if i_to_change <= 0:
            ans.append(''.join([str(x) for x in cand]))
            K -= 1
        while 0 < i_to_change < n_digit and K > 0:
            for k in range(10):
                cand[i_to_change] = k
                ans.append(''.join([str(x) for x in cand]))
                K -= 1
            i_to_change -= 1
        
        # else:
        #     ans.append(''.join([str(x) for x in cand]))
        #     K -= 1

        if cand[0] < 9:
            cand[0] += 1
        else:
            n_digit += 1
            cand = [1] + [9] * (n_digit - 1)
    for a in ans:
        print(a)
main()

