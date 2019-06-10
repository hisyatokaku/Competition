N, K = map(int, input().split())
S = input()

S += "!"
cur_char = S[0]
cur_char_count = 1
smart_S = ""
smart_count = []
for c in S[1:]:
    if cur_char == c:
        cur_char_count += 1
    else:
        smart_S += cur_char
        smart_count.append(cur_char_count)
        cur_char = c
        cur_char_count = 1

l = 0
r = 0
cnt_0 = 0
cur_sum = 0

ans_cand = []

# print("smart_S: ", smart_S)

while r == 0 or l < r:
    # print("l: {}, r: {}".format(l, r))
    while cnt_0 < K and r < len(smart_S) - 1:
        cur_sum += smart_count[r]
        if smart_S[r] == '0':
            cnt_0 += 1
        r += 1
        
    # proceed one more 
    if r < len(smart_S) and smart_S[r] == '1':
        cur_sum += smart_count[r]
        cnt_0 += 1
        r += 1

    ans_cand.append(cur_sum)

    if l < len(smart_S) and smart_S[l] == '0':
        cur_sum -= smart_count[l]
        cnt_0 -= 1
        l += 1

    else:
        if l < len(smart_S):
            cur_sum -= smart_count[l]
            cnt_0 -= 1
            l += 1
        if l < len(smart_S):
            cur_sum -= smart_count[l]
            cnt_0 -= 1
            l += 1


#print("smart_count: ", smart_count)
#print("ans_cand: ", ans_cand)
print(max(ans_cand))
