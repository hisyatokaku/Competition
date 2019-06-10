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

int x[N_MAX];
int y[N_MAX];
long int div = pow(10, 9) + 7;
long int fact(long int n); 
  
long int nCr(long int n, long int r) 
{
    return fact(n) / fact(r) / fact(n - r); 
} 

long int binomialCoeff(int n, int k) 
{ 
    int res = 1; 
  
    // Since C(n, k) = C(n, n-k) 
    if ( k > n - k ) 
        k = n - k; 
  
    // Calculate value of [n * (n-1) *---* (n-k+1)] / [k * (k-1) *----* 1] 
    for (int i = 0; i < k; ++i) 
    { 
        res *= (n - i); 
        res /= (i + 1); 
    } 
  
    return res; 
} 

// Returns factorial of n 
long int fact(long int n) 
{ 
    long int res = 1; 
    for (long int i = 2; i <= n; i++) 
        res = res * i; 
    return res; 
} 

long int distancesum(int arr[], int n) 
{ 
    // sorting the array. 
    sort(arr, arr + n); 
  
    // for each point, finding the distance. 
    int res = 0, sum = 0; 
    for (int i = 0; i < n; i++) { 
        res += (arr[i] * i - sum); 
        sum += arr[i]; 
    } 
  
    return res; 
} 

long int totaldistancesum(int x[], int y[], int n, int m) 
{ 
    return distancesum(x, n) + distancesum(y, m);
} 

int main(){
  int N, M, K;
  cin >> N >> M >> K;
  int row, col;
  int i=0;
  int j=0;

  rep(row, 0, N){
    rep(col, 0, M){
      x[i++] = row;
    }
  }
  rep(row, 0, N){
    rep(col, 0, M){
      y[j++] = col;
    }
  }
  long int manh = totaldistancesum(x, y, N*M, N*M) % div;
  long int num = binomialCoeff(N*M-2, K-2);
  long int ans = (manh * num) % div;
  cout << ans << endl;
  return 0;
}
