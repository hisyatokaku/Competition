def main():
    n, c = map(int, raw_input().split())
    x, v = [], []

    for _ in range(n):
        x_, v_ = map(int, raw_input().split())
        x.append(x_)
        v.append(v_)
    
    """
    x: position
    v: value
    
    dp[i+1][j]: maximum value up to index i from the position j
    
    how much is the current value?
    where are we curently?
    
    dp[i+1][j] = max(not to chose i-th one, choose i-th one)
               = max(dp[i][j], dp[i][x[i]] + )
    
    
    """
    
main()
