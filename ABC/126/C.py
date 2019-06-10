import math

N, K = map(int, input().split())

def f(n, k):
    return 0.5 ** math.ceil(math.log2(k/float(n)))
ans = 0
if K > N:
    for n in range(1, N+1):
       ans += f(n, K) * 1/N
       
else:
    for n in range(1, K):
        ans += f(n, K) * 1/N
    ans += float(N-K+1)/N
    
print(ans)
