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

ll dp[10001][2][2];

// compare with https://atcoder.jp/contests/dp/submissions/3936775
int main(){
    string K; cin >> K;
    int D; cin >> D;
    dp[0][0][0] = 1;
    rep(i, 0, K.length()){
        rep(j, 0, 2){
            for(int k=0; k<D; k++){
                for(int d=0; d <= (j ? 9 : K[i] - '0'); d++){
                    int new_mod = (k + d) % D;
                    dp[i+1][j || (d < K[i] - '0')][new_mod] += dp[i][j][k];
                    dp[i+1][j || (d < K[i] - '0')][new_mod] %= MOD;
                }
            }
        }
    }
    cout << (dp[K.length()][0][0] + dp[K.length()][1][0] - 1) % MOD << endl;
    return 0;
}


