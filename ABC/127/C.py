N, M = map(int, input().split())
l_max = 0
r_min = 10**5 + 1
for _ in range(M):
    l, r = map(int, input().split())
    l_max = max(l_max, l)
    r_min = min(r_min, r)
if r_min - l_max + 1 > 0:
    print(r_min - l_max + 1)
else:
    print("0")
