pascal_table = [[0 for i in range(901)] for j in range(901)]
def pascal(i,j):
    if i == 0 or j == 0 or i==j:
        pascal_table[i][j] = 1
        return 1
    else:
        if pascal_table[i][j] == 0:
            pascal_table[i][j] = pascal(i-1,j) + pascal(i-1,j-1)
        return pascal_table[i][j]

pas_list = []
for i in range(901):
    tmp_pas_list = []
    for j in range(i+1):
        tmp_pas_list.append(pascal(i,j))
    pas_list.append(tmp_pas_list)

def Comb(i,j):
    return pas_list[i][j]

R,C = map(int,raw_input().split())
X,Y = map(int,raw_input().split())
D,L = map(int,raw_input().split())

box = (R-X+1)*(C-Y+1)
combi = Comb(D+L,D)
print (box*combi)%(pow(10,9)+7)
