N = input()
S = raw_input()
ans,max_ = 0,0
for char in S:
    ans = ans + 1 if char is 'I' else ans - 1
    max_ = ans if max_ <= ans else max_
print max_
