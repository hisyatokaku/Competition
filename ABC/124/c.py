S = input()
length = len(S)

ans1, ans2 = 0, 0

# even: 0, odd: 1
for i in range(length):
    if i % 2 == 0 and S[i] == '0':
        pass
    elif i % 2 == 1 and S[i] == '1':
        pass
    else:
        ans1 += 1

for i in range(length):
    if i % 2 == 0 and S[i] == '1':
        pass
    elif i % 2 == 1 and S[i] == '0':
        pass
    else:
        ans2 += 1
        
print(min(ans1, ans2))
        
