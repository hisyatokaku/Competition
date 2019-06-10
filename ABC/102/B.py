n = int(input())
a = list(map(int, input().split()))

if max(a) - min(a) > 0:
    print(max(a)-min(a))
else:
    print(min(a) - max(a))
