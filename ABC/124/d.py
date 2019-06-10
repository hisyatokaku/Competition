N, K = map(int, input().split())
S = input()
new_S = []
count_S = []

cur_c = S[0]
cur_count = 0

new_S.append(cur_c)
for c in S:
    if c == cur_c:
        cur_count += 1
    else:
        new_S.append(c)
        count_S.append(cur_count)
        cur_count = 1
        cur_c = c
count_S.append(cur_count)        

new_count = []
st_ix = 0
if S[0] == '0':
    cur_sum = sum(count_S[:2*K])
    st_ix = 1
    new_count.append(cur_sum)
else:
    cur_sum = sum(count_S[:2*K+1])
    new_count.append(cur_sum)

en_ix = st_ix + 2*K + 1
cur_sum = sum(count_S[st_ix:en_ix])
new_count.append(cur_sum)

while en_ix < len(count_S):
    # shift st_ix
    st_ix = st_ix + 2
    en_ix = en_ix + 2
    if en_ix >= len(count_S):
        new_count.append(sum(count_S[st_ix:]))
    else:
        cur_sum -= (count_S[st_ix-2] + count_S[st_ix-1])
        cur_sum += (count_S[en_ix-2]
                        + count_S[en_ix-1])
    new_count.append(cur_sum)

print(max(new_count))
