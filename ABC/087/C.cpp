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
int A[101][101];

int main(){
  int N;
  cin >> N;
  int cur_sum = 0;
  int ans;
  rep(i, 0, N) cin >> A[0][i];
  rep(i, 0, N){
    cin >> A[1][i];
    cur_sum += A[1][i];
  }
  cur_sum += A[0][0];
  ans = cur_sum;
  
  rep(i, 0, N-1){
    cur_sum = (cur_sum + A[0][i+1] - A[1][i]); 
    ans = max(ans, cur_sum);
  }
  cout << ans << endl;
  return 0;
}
