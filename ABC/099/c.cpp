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

const int N_MAX = 1000001;
int dp[20][N_MAX];
int money[N_MAX];

int return_pow_max(int n, int d){
  int ret = 0;
  while(pow(d, ret) <= n){
    ret++;
  }
  ret--;
  return ret;
}

int main(){
  int n;
  cin >> n;
  
  int nine_max_ix = return_pow_max(n, 9);
  int six_max_ix = return_pow_max(n, 6);

  int money_ix = 0;
  money[money_ix] = 1;
  money_ix++;
  
  rep(i, 1, six_max_ix+1){
    money[money_ix] = pow(6, i);
    money_ix++;
  }
  
  rep(i, 1, nine_max_ix+1){
    money[money_ix] = pow(9, i);
    money_ix++;
  }
  
  // dp[i][j] ... using up to i-th index
  
  rep(row, 0, money_ix+1){
    dp[row][0] = 0;
  }
  
  rep(col, 1, n+1){
    dp[0][col] = 0;
    dp[1][col] = col;
  }
  
  rep(row, 1, money_ix){
    rep(col, 0, n+1){
      dp[row+1][col] = INT_MAX;
      if(col - money[row] >= 0){
	int max_k = col/money[row];
	dp[row+1][col] = min(dp[row][col]+1,
			     min(dp[row][col-money[row]]+1,
				 dp[row+1][col-money[row]]+1));
	dp[row+1][col] = min(dp[row][col], dp[row+1][col]);
	//rep(k, 0, max_k+1){
	  //dp[row+1][col] = min(dp[row][col]+1,
	  //		       min(dp[row][col-money[row]]+1, dp[row][col])); // use or not use
	//dp[row+1][col] = min(dp[row][col-k*money[row]]+k, min(dp[row][col], dp[row+1][col]));
	//}
      }
      else{
	dp[row+1][col] = dp[row][col]; // not use
      }
    }
  }
  /*
  rep(row, 0, money_ix+1){
    rep(col, 0, n+1){
      cout << dp[row][col] << " ";
    }
    cout << endl;
    }*/
 
  cout << dp[money_ix][n] << endl;
  
  return 0;
}
