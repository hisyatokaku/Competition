A, B = map(int, input().split())
ans = 0
i = 2
while i > 0:
    if i==2 and A == B:
        ans = 2 * A
        break

    elif A > B:
        ans += A
        A -= 1
    else:
        ans += B
        B -= 1
    i -= 1
print(ans)
