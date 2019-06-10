N = int(input())
S = list(input())

ans = 0
s_count = 0
if len(S) == 1:
    print(ans)
elif len(S) == 2:
    if S == ['#', '.']:
        print("1")
    else:
        print("0")
elif len(S) == 3:
    for i in range(len(S)-1):
        if S[i] == '#' and S[i+1] == '.':
            ans += 1
    print(ans)
            
else:
    for c in S[:-1]:
        if c=='#':
            s_count += 1
    for i in range(len(S)-3):
        if S[i:i+4] == ['.','#','.','.']:
            S[i:i+4] = ['.','.','.','.']
            
        elif S[i:i+4] == ['.','#','.','#']:
            S[i:i+4] = ['.','#','#','#']

        elif S[i:i+4] == ['#','#','.','.']:
            S[i:i+4] = ['#','#','#','.']

        elif S[i:i+4] == ['#','#','.','#']:
            S[i:i+4] = ['#','#','#','#']
        else:
            continue
        ans += 1

    print(min(s_count, ans, len(S)-s_count))
print(S)
