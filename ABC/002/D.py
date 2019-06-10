import math

def check_rel(rel,tmp):
    if len(tmp) <= 1:
        return True
    for i in range(len(tmp)):
        for j in range(i+1,len(tmp)):
            if ([tmp[i],tmp[j]] in rel) or ([tmp[j],tmp[i]] in rel):
                continue
            else:
                return False
    return True
        

def solve():
    N,M = map(int,raw_input().split())
    rel = [map(int,raw_input().split()) for i in range(M)]
    ans = []
    if M == 0:
        return 1
    for i in range(1,pow(2,N)):
        tmp = []
        bit = "%013d"%(int(format(i,'b')))
        for j in range(len(bit)):
            if bit[j] == str(1):
                tmp.append(len(bit)-j)
        if check_rel(rel,tmp):
            ans.append(tmp)
    #print ans
    max_ = 0
    for a in ans:
        max_ = len(a) if len(a) > max_ else max_
    return max_
print solve()

