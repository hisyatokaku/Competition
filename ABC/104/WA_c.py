import math

D, G = map(int, input().split())
d_s, g_s = [], []
for _ in range(D):
    d,g = map(int, input().split())
    d_s.append(d)
    g_s.append(g)

def solve(cur_G, cur_num):
    global d_s
    global g_s
    possible = []

    new_p = [(ix+1)*100 + g/d for (ix, (d,g)) in enumerate(zip(d_s, g_s))]
    max_p = max(new_p)
    max_p_ix = new_p.index(max_p)

    if (max_p_ix+1) * 100 * d_s[max_p_ix] + g_s[max_p_ix]< cur_G:
        cur_G -= d_s[max_p_ix] * (max_p_ix+1) * 100 + g_s[max_p_ix]
        new_num = cur_num + g_s[max_p_ix]
        return solve(cur_G, cur_num + new_num)

    else:
        while cur_G > 0:
            d, g = d_s[-1], g_s[-1]
            cur_G -= d
            cur_num += 1
            d_s[-1] -= 1
            if d_s[-1] == 0:
                cur_G -= g
                d_s = d_s[:-1]
                g_s = g_s[:-1]
    return cur_num
        
    """
    for ix, (d, g) in enumerate(zip(d_s, g_s)):
        m = d*(ix+1)*100
        if m + g >= cur_G:
            possible.append([m, d])
        num = cur_G/(100*(ix+1))
        if math.ceil(num) <= d:
            possible.append([cur_G, num])
    if len(possible)>0:
        min_num = min([x[1] for x in possible])
        return min_num + cur_num
    else:
        d = d_s[-1]
        g = g_s[-1]
        cur_G -= d * (ix+1) * 100 + g
        d_s = d_s[:-1]
        g_s = g_s[:-1]
        return solve(cur_G, cur_num + d)
    """
print(int(solve(G, 0)))
