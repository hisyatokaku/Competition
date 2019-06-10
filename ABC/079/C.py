S = input()
n = 4

def f(S, n):
    for i in range( 1 << n-1 ):
        cand_str = ""
        cand_str += S[0]

        # loop for 0th, 1th, ..., n-2th digits
        for j in range(n-1):

            # get n-2th bit when j=0 
            t = i & (1 << n-2-j)
            if t:
                cand_str += "+"
            else:
                cand_str += "-"
            cand_str += S[j+1]
            
        if eval(cand_str) == 7:
            return cand_str + "=7"

print(f(S, n))
        
        
    
