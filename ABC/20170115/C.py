def prime_decomposition(n):
    i = 2
    table = []
    while i * i <= n:
        while n % i == 0:
            n /= i
            table.append(i)
        i += 1
    if n > 1:
        table.append(n)
    return table
N = input()
ans = 1
nlist = [0]*1000
for i in xrange(1,N+1):
    for j in prime_decomposition(i):
        nlist[j-1] += 1
        
for j in nlist:
    ans *= (j+1)

print ans%1000000007
