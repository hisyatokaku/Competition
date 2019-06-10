S = input()
T = input()
c2pos=dict()
s_c2pos = dict()

for ix, c in enumerate(S):
    if s_c2pos.get(c) == None:
        s_c2pos[c] = [ix]
    else:
        s_c2pos[c].append(ix)

for ix, c in enumerate(T):
    if c2pos.get(c) == None:
        c2pos[c] = [ix]
    else:
        c2pos[c].append(ix)

res = "Yes"

for k, v in c2pos.items():
    if len(v) < 1:
        continue

    if len(set([S[_v] for _v in v])) != 1:
        res = "No"

    if s_c2pos[S[v[0]]] != v:
        res = "No"
    
print(res)
