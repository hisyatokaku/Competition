n = int(input())
a = list(map(int, input().split()))
a = [x-i-1 for i,x in enumerate(a)]

a = sorted(a)

med1 = a[len(a)//2]
med2 = a[len(a)//2 - 1]



sum1 = sum([abs(x - med1) for x in a])
sum2 = sum([abs(x - med2) for x in a])
print(min(sum1, sum2))
