N, M = map(int, input().split())
A = map(int, input().split())
A = sorted(A) # ascending

B_C = []
for _ in range(M):
    b, c = map(int, input().split())
    B_C.append((b, c))
B_C = sorted(B_C, key=lambda x: x[1], reverse=True)

cur_a_ix = 0
ans = 0

for b, c in B_C:
    while b and cur_a_ix < len(A):
        if A[cur_a_ix] < c:
            ans += c
        else:
            break
        b -= 1
        cur_a_ix += 1
ans += sum(A[cur_a_ix:])
print(ans)
    
