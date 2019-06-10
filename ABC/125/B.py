N = int(input())
S = input()
K = int(input())

tar = S[K-1]
ans = ""
for c in S:
    if c != tar:
        ans += "*"
    else:
        ans += c
print(ans)
