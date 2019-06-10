from itertools import combinations

S = str(input())
n = len(S)

ans = 0
for i in range(1 << (n-1)):
    cur_ans = int(S[0])
    for j in range(n-1):
        add_plus = (i >> (n-2-j)) & 1
        if add_plus:
            ans += cur_ans
            cur_ans = 0
        else:
            cur_ans *= 10
        cur_ans += int(S[j+1])
    ans += cur_ans
print(ans)            

    
'''
pos = [i for i in range(len(S)-1)]
insert_indices = [comb for i in range(len(S)) for comb in combinations(pos, i)]

ans = 0

for inds in insert_indices:
    cur_ix = 0
    cur_ans = 0
    while cur_ix < len(S):
        cur_ans += int(S[cur_ix])
        if cur_ix == len(S)-1:
            break
        if cur_ix in inds:
            ans += cur_ans
            cur_ans = 0
        else:
            cur_ans *= 10
        cur_ix += 1
    ans += cur_ans
    
print(ans)
'''
