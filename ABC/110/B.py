N, M, X, Y = map(int, input().split())
x = map(int, input().split())
y = map(int, input().split())

x_max = max(x)
y_min = min(y)

is_war = True

for z in range(X+1, Y+1):
    if x_max < z and z <= y_min:
        is_war = False
if is_war:
    print("War")
else:
    print("No War")
