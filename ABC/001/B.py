#coding: utf-8
m = input()
vv = 0
if m < 100:
    vv = "00"
    
elif 100 <= m and m <= 5000:
    vv = m/100
#    print "vv=",vv
    if len(str(vv)) == 1:
        vv = str("0"+str(vv))

elif 6000 <= m and m <= 30000:
    vv = m/1000 + 50
    
elif 35000 <= m and m <= 70000:
    vv = (m/1000 - 30)/5 + 80

elif 70000 < m :
    vv = 89    

print vv
