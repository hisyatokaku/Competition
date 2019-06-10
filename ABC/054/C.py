import pdb

N, M = map(int, input().split())
a, b = [], []
mat = [[0 for _ in range(N)] for _ in range(N)]

for _ in range(M):
    _a, _b = map(int, input().split())
    a.append(_a)
    b.append(_b)
    mat[_a-1][_b-1] = 1
    mat[_b-1][_a-1] = 1

visited = set()
ans = 0

def dfs(num):
    global ans
    #pdb.set_trace()
    visited.add(num)
    if len(visited) == N:
        ans += 1
        return 
    
    for next_num, connected in enumerate(mat[num]):
        if not connected:
            continue
        if next_num in visited:
            continue
        visited.add(next_num)
        dfs(next_num)
        visited.remove(next_num)
    return

def main():
    dfs(0)
    print(ans)

main()
