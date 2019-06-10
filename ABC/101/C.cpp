#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <map>
#include <stack>
#include <queue>
#include <deque>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <climits>
#include <cstring>
#define rep(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))

using namespace std;

const int N_MAX = 1000000;
int a[N_MAX];

int calc_num(int st, int en, int k, int n){
  int left_time = (st - 0)/(k-1) + (st%(k-1) != 0);
  int right_time = (n-1 - en)/(k-1) + ((n-1-en)%(k-1) != 0);
  return left_time + right_time + 1;
}

int main(){
  int n, k;
  cin >> n >> k;

  int min_ele = N_MAX;
  int min_ix = -1;
  
  rep(i, 0, n) cin >> a[i];
  rep(i, 0, n){
    if(a[i] < min_ele){
      min_ele = a[i];
      min_ix = i;
    }
  }
  
  int lower_st = max(0, min_ix + 1 - k);
  int ans = INT_MAX;
  rep(st, lower_st, min_ix+1){
    ans = min(ans, calc_num(st, st+k-1, k, n));
  }
  cout << ans << endl;
  /*
  int rightlen = n - min_ix - 1; // not include min element
  int right_time = rightlen/(k-1) + (rightlen%(k-1) != 0);

  // if(rightlen == k) right_time = 1;

  int hamide =  k - rightlen%(k-1) - 1;
  if(rightlen%(k-1)==0) hamide = 0;
  int leftlen = max(0, min_ix - hamide);
  int left_time = leftlen/(k-1) + (leftlen%(k-1) != 0);
  */

  
  /*
  cout << "rightlen: " << rightlen << endl;
  cout << "leftlen: " << leftlen << endl;
  cout << "right_time: " << right_time << endl;
  cout << "left_time: " << left_time << endl;
  */
  //cout << right_time + left_time << endl;
  return 0;
}
