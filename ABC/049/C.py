def solve(S):
    r_ix = len(S)
    while len(S):
        is_hit = False

        for word in ['dream', 'dreamer', 'erase', 'eraser']:
            l_ix = r_ix - len(word)
            if S[l_ix:r_ix] == word:
                S = S[:l_ix]
                r_ix = l_ix
                is_hit = True

        if not is_hit:
            return "NO"
                
    return "YES"

if __name__ == "__main__":
    S = input()
    print(solve(S))
