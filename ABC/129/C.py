N, M = map(int, input().split())
a = []
s = [0 for _ in range(N+1)]
for _ in range(M):
    a.append(int(input()))

s[0] = 0
s[1] = 1
s[2] = 2

cur_ix = 0
for i in range(1, 3):
    if a[cur_ix] == i:
        s[i] = 0
        cur_ix += 1
    else:
        if i == 1:
            s[i] = 1
        elif i == 2:
            s[i] = s[i-1] + s[i-2] + 1

for i in range(3, N+1):
    if cur_ix < len(a) and a[cur_ix] == i:
        s[i] = 0
        cur_ix += 1
    else:
        s[i] = (s[i-1] + s[i-2]) % 1000000007

print(s[N])
