W = raw_input()
boin = ['a','i','u','e','o']
answer = ''
for char in W:
    if char not in boin:
        answer+=char
        print answer
        
