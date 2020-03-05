import math,string,itertools,fractions,heapq,collections,re,array,bisect,sys,random,time,copy,functools
from collections import deque

sys.setrecursionlimit(10**7)
inf = 10**20
mod = 10**9 + 7

DR = [1, -1, 0, 0]
DC = [0, 0, 1, -1]

def LI(): return [int(x) for x in sys.stdin.readline().split()]
def LI_(): return [int(x)-1 for x in sys.stdin.readline().split()]
def LF(): return [float(x) for x in sys.stdin.readline().split()]
def LS(): return sys.stdin.readline().split()
def I(): return int(sys.stdin.readline())
def F(): return float(sys.stdin.readline())
def S(): return input()
     
def main():
    string = S()
    kenban = 'WBWBWWBWBWBW' * 10
    for i in range(len(kenban) - 20):
        if kenban[i:i + len(string)] == string:
            break
    dic = {
        0: 'Do',
        2: 'Re',
        4: 'Mi',
        5: 'Fa',
        7: 'So',
        9: 'La',
        11: 'Si',
    }
    print(dic[i])
main()

