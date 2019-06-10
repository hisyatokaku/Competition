N = input()
H = list(map(int, input().split()))

cur_max_h = H[0]
ans = 0

for i in range(len(H)):
    if cur_max_h <= H[i]:
        ans += 1
        cur_max_h = H[i]
print(ans)
