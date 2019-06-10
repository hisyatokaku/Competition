#coding: utf-8
from decimal import Decimal

def return_Deg(deg):
    a = 22.5
    deg = deg - 11.25
    if 0 <= deg and deg < a*1:
        return "NNE" 
    elif a*1 <= deg and deg < a*2:
        return "NE"
    elif a*2 <= deg and deg < a*3:
        return "ENE"
    elif a*3 <= deg and deg < a*4:
        return "E"
    elif a*4 <= deg and deg < a*5:
        return "ESE"
    elif a*5 <= deg and deg < a*6:
        return "SE"
    elif a*6 <= deg and deg < a*7:
        return "SSE"
    elif a*7 <= deg and deg < a*8:
        return "S"
    elif a*8 <= deg and deg < a*9:
        return "SSW"
    elif a*9 <= deg and deg < a*10:
        return "SW"
    elif a*10 <= deg and deg < a*11:
        return "WSW"
    elif a*11 <= deg and deg < a*12:
        return "W"
    elif a*12 <= deg and deg < a*13:
        return "WNW"
    elif a*13 <= deg and deg < a*14:
        return "NW"
    elif a*14 <= deg and deg < a*15:
        return "NNW"
    else:
        return "N"

def return_Dis(dis):
    dis = dis / 60.0
    dis = float(Decimal(str(dis)).quantize(Decimal('.0'),rounding = 'ROUND_HALF_UP'))
    #文字にしないとずれる
    if 0 <= dis and dis <= 0.2:
        return 0
    elif 0.3 <= dis and dis <= 1.5:
        return 1
    elif 1.6 <= dis and dis <= 3.3:
        return 2
    elif 3.4 <= dis and dis <= 5.4:
        return 3
    elif 5.5 <= dis and dis <= 7.9:
        return 4
    elif 8.0 <= dis and dis <= 10.7:
        return 5
    elif 10.8 <= dis and dis <= 13.8:
        return 6
    elif 13.9 <= dis and dis <= 17.1:
        return 7
    elif 17.2 <= dis and dis <= 20.7:
        return 8
    elif 20.8 <= dis and dis <= 24.4:
        return 9
    elif 24.5 <= dis and dis <= 28.4:
        return 10
    elif 28.5 <= dis and dis <= 32.6:
        return 11
    elif 32.7 <= dis:
        return 12

if __name__ == "__main__":
    Deg,Dis = map(int,raw_input().split())
    #should be devided by 10
    Dir = return_Deg(Deg/10.0)
    W = return_Dis(Dis)
    if W == 0:
        Dir = "C"
    print Dir,W
