s = raw_input()
s = list(s)

K = input()
counter = 0

def solve(s,K,counter):
    i = K # i = num of character
    tmp = []
    for k in range(len(s) - i + 1):
        str = s[k:k+i]
        out = "".join(str)
        tmp.append(out)
    tmp = list(set(tmp))
    counter += len(tmp)
#    print tmp
    print counter

def solve2():
    print 0

if __name__ == "__main__":
    if(len(s) < K):
        solve2()
    else:
        solve(s,K,counter)
