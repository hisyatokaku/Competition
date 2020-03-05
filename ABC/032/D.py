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
     
def all_comb(a):
    cands_a = []
    for i in range(1 << len(a)):
        cand = [0, 0]
        for j in range(len(a)):
            use_j = (i >> j) & 1
            if use_j:
                cand[0] += a[j][0]
                cand[1] += a[j][1]
        cands_a.append(cand)
    return cands_a

def half_brute(v, w, W):
    N = len(v)
    v_a, v_b = v[:N//2], v[N//2:]
    w_a, w_b = w[:N//2], w[N//2:]
    set_a = [(_v, _w) for _v, _w in zip(v_a,w_a)]
    set_b = [(_v, _w) for _v, _w in zip(v_b,w_b)]

    # 全組み合わせを列挙
    set_a = all_comb(set_a)
    set_b = all_comb(set_b)

    # 全組み合わせの中で下位互換の要素を捨てる
    set_a = sorted(set_a, key=lambda x: (x[1], -x[0]))

    cur_max_v = -1 
    new_set_a = []
    for v, w in set_a:
        if cur_max_v >= v:
            continue
        cur_max_v = v
        new_set_a.append((v, w))

    ans = 0

    #print("seta: {}".format(set_a))
    #print("setb: {}".format(set_b))

    #print("new_seta: {}".format(new_set_a))
    a_w = [x[1] for x in new_set_a]

    for v, w in set_b:
        max_weight = W - w
        if max_weight < 0:
            continue
        a_ix = bisect.bisect_right(a_w, max_weight)
        if w + a_w[a_ix - 1] <= W:
            ans = max(v + new_set_a[a_ix-1][0], ans)
    print(ans)


def dp1(V, w, W):
    # classic one
    N = len(V)
    dp = [[0 for _ in range(W+1)] for __ in range(N+1)]
    for i in range(N):
        for j in range(W+1):
            if j - w[i] >= 0:
                dp[i+1][j] = max(dp[i][j], dp[i][j-w[i]]+V[i])
            else:
                dp[i+1][j] = dp[i][j]
    print(dp[N][W])

def dp2(V, w, W):
    N = len(V)
    max_V = 1000 * 200
    dp = [[0 for _ in range(max_V+1)] for __ in range(N+1)]
    
    for j in range(W+1):
        dp[0][j] = inf

    for i in range(N):
        for j in range(W+1):
            # dp[i+1][j] = index: iまでの中で価値jを達成する最小の重み
            # i番目を使わない or i番目を使って価値jが達成
            if j - V[i] >= 0:
                dp[i+1][j] = min(dp[i][j], dp[i][j - V[i]] + w[i]) 
            else:
                dp[i+1][j] = dp[i][j]
    # why??
    dp[0][0] = 0

    ans = 0
    for i in range(N+1):
        for j in range(max_V+1):
            if dp[i][j] <= W:
                ans = max(ans, j)
    print(ans)

def main():
    N, W = LI()
    v, w = [], []
    for _ in range(N):
        _v, _w = LI()
        v.append(_v)
        w.append(_w)
    dp1(v, w, W)
    dp2(v, w, W)
    if N <= 30:
        half_brute(v, w, W)

    elif max(W) <= 1000:
        dp1(v, w, W)

    elif max(v) <= 1000:
        dp2(v, w, W)

    return

main()

