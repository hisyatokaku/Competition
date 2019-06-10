# -*- coding: utf-8 -*-
def solve(N,K,s):
    Nlist = range(N)
    tmp = reduce(lambda x,y:x+y,s)
    if tmp < K:
        Nlist.reverse()

    if min(s) == 0:
        return Nlist[0]+1

    if K == 0:
        return 0

    for i in Nlist:
        i = i + 1
        for j in xrange(N - i + 1):
            tmp = reduce( lambda x,y:x*y, s[j:j+i] )
            if (tmp<=K):
                return i
    return 0

def multiple(l):
    if len(l) == 0:
        return 0
    else:
        return reduce(lambda x,y:x*y,l)

def shaku(N,K,s):
    left = 0
    right= 1
    ans  = 0
    now  = 1
    if 0 in s:
        return len(s)
#    print "s=",
#    print s
    while (right <= len(s)) or (left <= len(s)-1):
        # print "right =",
        # print right
        # print "left =",
        # print left
        # print "s[left:right]=",
        # print s[left:right]

        if multiple(s[left:right]) <= K:
            ans = max(ans,right-left)
            right += 1
            if (right > len(s)):
                break
        elif multiple(s[left:right]) > K:
            right -= 1
            left  += 1
            if(left >= right):
                right += 1
                if(left >= right):
                    right += 1
    return ans
    
def shaku2(N,K,s):
    left,right,ans,now = 0,0,0,1
    if 0 in s:
        return len(s)
    while(1):
        if(now*s[right] <= K):
            ans = max(ans,right)
            now *= s[right]
            right += 1
        else:

            if (left == right):
                right += 1
            else:
                now /= s[left]
                left += 1

if __name__ == "__main__":
    N,K = map(int,raw_input().split())
    s = [input() for i in xrange(N)]
    print shaku2(N,K,s)

