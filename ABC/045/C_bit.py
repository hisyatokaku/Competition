
def f():
    s = input()
    l = len(s)
    sa = [c for c in s]
    m = 2**(l-1)
    r = 0
    for i in range(m):
        si = sa[0]
        for j in range(l-1):
            t = 2**j
            if i & t:
                si += '+'
            si += sa[j+1]
        r += eval(si)
    return r
