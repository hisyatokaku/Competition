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

ll dp[3001][3001];

void d(int dp[3001][3001], int N){
    rep(i, 0, N){
        rep(j, 0, N){
            cout << dp[i][j] << ", ";
        }
        cout << endl;
    }
}

int main(){
    int N; cin >> N;
    string S; cin >> S;
    rep(i, 0, N){
        dp[0][i] = 1;
    }
    rep(i, 1, N){
        rep(j, 0, N-i+1){
            if (S[i-1] == '<'){
                dp[i][j] += (dp[i-1][j] % MOD);
                dp[i][N-i] -= (dp[i-1][j] % MOD);
                dp[i][j] %= MOD;
                dp[i][N-i] %= MOD;
            } else if (S[i-1] == '>'){
                dp[i][0] += (dp[i-1][j] % MOD);
                dp[i][j] -= (dp[i-1][j] % MOD);
                dp[i][0] %= MOD;
                dp[i][j] %= MOD;
            }
        }
        rep(j, 1, N+1){
            dp[i][j] += dp[i][j-1] % MOD;
            dp[i][j] %= MOD;
        }
    }
    ll ans = 0;
    rep(j, 0, N){
        ans += (dp[N-1][j] % MOD);
        ans %= MOD;
    }
    cout << ans % MOD << endl;
    return 0;
}
