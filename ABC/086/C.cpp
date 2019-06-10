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

int main(){
  int N;
  cin >> N;
  vector<int> T;
  vector<int> X;
  vector<int> Y;
  int t, x, y;
  rep(i, 0, N){
    cin >> t >> x >> y;
    T.push_back(t);
    X.push_back(x);
    Y.push_back(y);
  }

  int cur_t = 0;
  int cur_x = 0;
  int cur_y = 0;

  string ans = "Yes";
  
  rep(i, 0, N){
    int step = (T[i] - cur_t) - abs(cur_x - X[i]) - abs(cur_y - Y[i]);
    if(step < 0 || step % 2 != 0) ans = "No";
    cur_t = T[i];
    cur_x = X[i];
    cur_y = Y[i];
  }
  cout << ans << endl;
  
  return 0;
}
