import collections
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


def solve2(S):
    word = ['dream', 'dreamer', 'erase', 'eraser']
    buf = []
    for ch in S:
        buf.append(ch)
    curchar = ''
    while len(buf) > 0:
        c = buf.pop()
        curchar = c + curchar
        if curchar in word:
            curchar = ''

    if curchar == '':
        return "YES"

    return "NO"

if __name__ == "__main__":
    S = input()
    print(solve(S))
