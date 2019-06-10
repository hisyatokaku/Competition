from itertools import combinations 

N = int(input())
d = {'M':0, 'A':0, 'R':0, 'C':0, 'H':0}
ans = 0
for _ in range(N):
    s = input()
    head = s[0]
    if d.get(head) != None:
        d[head] += 1

for chars in combinations("MARCH", 3):
    ans += d[chars[0]] * d[chars[1]] * d[chars[2]]
print(ans)
