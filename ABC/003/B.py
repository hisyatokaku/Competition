S=raw_input()
T=raw_input()

LOSE = "You will lose"
WIN  = "You can win"
changable = ['a','t','c','d','o','e','r']
def solve(S,T):
    for s,t in zip(S,T):
        if s==t:
            continue
        elif s=="@":
            if t in changable:
                continue
            else:
                return LOSE
        elif t=="@":
            if s in changable:
                continue
            else:
                return LOSE
        else:
            return LOSE
    return WIN
print solve(S,T)
