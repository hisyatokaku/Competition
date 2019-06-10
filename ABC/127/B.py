r, d, x = map(int, input().split())
def f(r, d, x):
    return r * x - d

for _ in range(10):
    print(f(r, d, x))
    x = f(r, d, x)
