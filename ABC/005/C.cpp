#include <iostream>
#include <queue>
#include <stack>
#include <cstdio>
#include <vector>
#include <sstream>

using namespace std;

const int N_MAX = 1000000;

int main(void){
  int a, b, c, x, y;
  cin >> a >> b >> c >> x >> y;
  int ans = min(a*x+b*y, min(2*c*max(x, y), 2*c*min(x,y) + (x>y?(x-y)*a:(y-x)*b)));
  cout <<  ans << endl;
  return -1;  
}
