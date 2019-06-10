N, Y = map(int, input().split())
Y /= 1000
Y = int(Y)
max_N = 2000
ans_x, ans_y, ans_z = -1, -1, -1

for y in range(max_N+1):
    for z in range(max_N+1):
        if 4*y + 9*z == Y - N and y + z <= N:
            ans_y, ans_z = y, z
            break
        
if ans_y != -1:
    ans_x = N - ans_y - ans_z
    if ans_x < 0:
        ans_x, ans_y, ans_z = -1, -1, -1
        
print("{} {} {}".format(ans_z, ans_y, ans_x))
