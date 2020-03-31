#include "bits/stdc++.h"
#define DEBUG(x) cout<<#x<<": "<<x<<endl;
#define DEBUG_VEC(v) cout<<#v<<":";for(int i=0;i<v.size();i++) cout<<" "<<v[i]; cout<<endl
#define vi vector<int>
#define vl vector<ll>
#define vii vector< vector<int> >
#define vll vector< vector<ll> >
#define vlll vector< vector< vector<ll> > >
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
    ll N, W; cin >> N >> W;
    vl w;
    vl v;
    rep(i, 0, N){
        ll _w, _v; cin >> _w >> _v;
        w.push_back(_w);
        v.push_back(_v);
    }
    ll w0 = w[0];
    rep(i, 0, N){
        w[i] -= w0;
    }
    vlll dp(N+1, vll(301, vl(N+1, 0)));
    /* rep(i, 1, N+1){ */
    /*     dp[i][0][0] = -INF; */
    /* } */
    rep(i, 1, N+1){
        rep(j, 0, 301){
            rep(k, 1, N+1){
                if(j - w[i-1] >= 0){
                    dp[i][j][k] = max(
                            dp[i-1][j][k], dp[i-1][j-w[i-1]][k-1] + v[i-1]
                            );
                } else dp[i][j][k] = dp[i-1][j][k];
                }
            }
        } 
    ll ans = 0;
    rep(j, 0, 3*N+1){
        rep(k, 0, N+1){
            ll weight = k * w0 + j;
            if(weight <= W){
                ans = max(ans, dp[N][j][k]);
            }
        }
    }
    cout << ans << endl;
    return 0;
}


