N=input()

def sol(N):
    N = N%30
    c = [1,2,3,4,5,6]
    for i in range(N):
        tmp = c[i%5+1]
        c[i%5+1] = c[i%5]
        c[i%5] = tmp
    return c

#for i in range(N):
#    print "{}:{}".format(i+1,sol(i+1))

print "".join(map(str,sol(N)))

