a,b,c,x,y = map(int, raw_input().split())
ans = min(a*x + b*y, min(2*c*max(x,y), 2*c*min(x,y) + (x-y)*a if x>y else 2*c*min(x,y) + (y-x)*b))
print(ans)
