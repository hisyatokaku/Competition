import numpy as np

N,W = map(int,raw_input().split())
value = [0]
wei = [0]

for i in range(N):
    a,b = map(int,raw_input().split())
    value.append(a)
    wei.append(b)

val = np.zeros((N+1)*W).reshape((N+1),W)

def mark(list,i,j):
    list[i+1][j] = list[i][j]
    list[i+1][j + wei[i+1]] = 
