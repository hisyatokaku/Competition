
def decide(lh,rh,target):
    if target < lh:
        return lh - target
    elif target > rh:
        return -1
    else:
        return 0

def solve(A,L,H):
    for num in A:
        print decide(L,H,num)

if __name__ == "__main__":
    L,H = map(int,raw_input().split())
    N = input()
    A = []
    for i in xrange(N):
        A.append(input())

    solve(A,L,H)
    
