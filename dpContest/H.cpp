#include "bits/stdc++.h"
#define DEBUG(x) cout<<#x<<": "<<x<<endl;
#define DEBUG_VEC(v) cout<<#v<<":";for(int i=0;i<v.size();i++) cout<<" "<<v[i]; cout<<endl
#define vi vector<int>
#define vl vector<ll>
#define vii vector< vector<int> >
#define vll vector< vector<ll> >
#define vs vector<string>
#define pii pair<int,int>
#define pis pair<int,string>
#define psi pair<string,int>
#define pll pair<ll,ll>
#define rep(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))
#define MOD 1000000007
#define mod 1000000009
#define pi 3.14159265358979323846
#define Sp(p) cout<<setprecision(15)<< fixed<<p<<endl;
int dx[4] = { 1,0,-1,0 }, dy[4] = { 0,1,0,-1 };

int dx2[8] = { 1,1,0,-1,-1,-1,0,1 }, dy2[8] = { 0,1,1,1,0,-1,-1,-1 };
typedef long long ll;
const int inf = 1000000001;
const ll INF = 1e18 * 4;
using namespace std;

int main(){
    int H, W;
    cin >> H >> W;
    char S[1002][1002] = {};
    rep(i, 0, H){
        rep(j, 0, W){
            cin >> S[i][j];
        }
    }
    int dp[1002][1002];
    rep(i, 0, H+1){
       rep(j, 0, W+1){
          dp[i][j] = 0; 
       }
    }
    dp[1][0] = 1;

    rep(i, 1, H+1){
        rep(j, 1, W+1){
            if(S[i-1][j-1] == '.'){
                dp[i][j] = dp[i-1][j] % MOD + dp[i][j-1] % MOD; 
                dp[i][j] = dp[i][j] % MOD;
            }
        }
    }
    cout << dp[H][W] << endl;
    
    return 0;
}


