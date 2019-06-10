R, G, B = map(int, raw_input().split())
R = R-1
G = G-1
B = B-1
R_box = [0] * 150 + [-1] + [0] * 150
G_box = [0] * 150 + [-1] + [0] * 150
B_box = [0] * 150 + [-1] + [0] * 150

def sigma(num):
    return sum(range(1, num+1))

if R <= 51 and G <= 51 and B <= 51:
    ans = 0
    R_l, R_r = R/2, R-R/2
    G_l, G_r = G/2, G-G/2
    B_l, B_r = B/2, B-B/2

    var = [R_l, R_r, G_l, G_r, B_l, B_r]
    for v in var:
        ans += sigma(v)
    
    print ans
