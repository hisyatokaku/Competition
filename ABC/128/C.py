N, M = map(int, input().split())
K = []
S = []
for i in range(M):
    k, *s = list(map(int, input().split()))
    s_bin = 0
    for j in s:
        s_bin += 1 << j
    K.append(k)
    S.append(s_bin)
P = list(map(int, input().split()))

ans = 0

for i in range(2**N):
    for j in range(M):
        if bin(i & S[j]).count('1') % 2 != P[j]:
            break
    else:
        ans += 1
print(ans)
