#coding:utf-8

def min_to_hour(time):
    time = int(time)*5
    hour = "%02d"%(time/60)
    min =  "%02d"%(time%60)
    return str(hour)+str(min)

def hour_to_min(time):
    #time = str(time)
    time = "%04d"%(time)
    return 60*int(time[:2])+int(time[2:])

def round_time(timeandtime):
    st,en = hour_to_min(timeandtime[0]),hour_to_min(timeandtime[1])
    ans = []
    res = st%5
    st = st - res
    
    res_ = en%5
    en = en + (5-res_) if res_ != 0 else en
    return [st/5,en/5]

N = input()
field = [0]*(1+24*60/5)
ans = []
sum_ = 0
_ = [map(int,raw_input().split('-')) for i in range(N)]
_ = [round_time(i) for i in _]
#print _

for i in _:
    st , en = i[0],i[1]
    field[st] += 1
    field[en] -= 1

for num in field:
    sum_ += int(num)
    ans.append(sum_)
flag = False
res = []
for i in range(len(ans)):
    if ans[i] != 0 and flag == False:
        flag = True
        tmp = min_to_hour(i)
    if ans[i] == 0 and flag == True:
        flag = False
        tmp2 = min_to_hour(i)
        res.append([tmp,tmp2])
for i in res:
    print "{}-{}".format(i[0],i[1])
