# -*- coding: utf-8 -*-

def make_new_list(taka,i,a):
    if taka > i:
        return a[i:taka+1]
    elif taka < i:
        return a[taka:i+1]
    else:
        return 0

def taka(list):
    if list == 0:
        return -2501
    taka_point = [x for (i,x) in enumerate(list) if i % 2 == 0]
    taka = reduce(lambda x,y: x + y , taka_point)
    return taka

def aoki(list):
    if list == 0:
        return -2501
    aoki_point = [x for (i,x) in enumerate(list) if i % 2 == 1]
    aoki = reduce(lambda x,y: x + y , aoki_point)
    return aoki

if __name__ == "__main__":
    N = input()
    a = map(int,raw_input().split())
    answer = -2501
    for i in range(N):
        taka_score = []
        aoki_score = []
        for j in range(N):
            list = make_new_list(i,j,a)
            #print list
            print "i,j = %d,%d" %(i,j)
            print "list=",
            print list
            # print "taka(list)=",
            # print taka(list)
            # print "aoki(list)=",
            # print aoki(list)

            taka_score.append(taka(list))
            aoki_score.append(aoki(list))
            
            tmp = taka_score[aoki_score.index(max(aoki_score))]
            #print tmp
            answer = max(answer,tmp)
    print answer
