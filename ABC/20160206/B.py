# -*- coding: utf-8 -*-
def search(S,P):
    if (max(P) >= sum(P)/2 + 1):
        print S[P.index(max(P))]
    else:
        print "atcoder"

if __name__ == "__main__":
    N = input()

    S = []
    P = []

    for i in xrange(N):
        s,p = raw_input().split()
        S.append(s)
        P.append(p)

    P = map(int,P)
    search(S,P)
