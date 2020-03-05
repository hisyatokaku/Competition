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
    int N, M, R;
    cin >> N >> M >> R;
    vi r(R);
    vii G(N, vi(N, inf));
    rep(i, 0, R){
        cin >> r[i];
        r[i]--;
    }
    rep(i, 0, M){
        int a, b, c;
        cin >> a >> b >> c;
        a--; b--;
        G[a][b] = c;
        G[b][a] = c;
    }
    rep(k, 0, N){
        rep(i, 0, N){
            rep(j, 0, N){
                G[i][j] = min(G[i][j], G[i][k] + G[k][j]);
            }
        }
    }
    vll dp(1<<(R+1), vl(R, INF));
    rep(j, 0, R) dp[0][j] = 0;
    rep(i, 0, R){
        dp[1 << i][i] = 0;
    }
    rep(i, 0, 1 << R){
        rep(j, 0, R){
            if(1 && (i >> j)){
                int prev_i = i ^ (1 << j);
                rep(k, 0, R){
                    if(1 && (prev_i >> k)){
                        int r1 = r[k];
                        int r2 = r[j];
                        /* DEBUG(r1); */
                        /* DEBUG(r2); */
                        /* DEBUG(dp[i][j]); */
                        dp[i][j] = min(dp[i][j], dp[prev_i][k] + G[r1][r2]);
                    }
                }
            }
        }
    }
    ll ans = INF;
    rep(j, 0, R){
        ans = min(ans, dp[(1<<R) - 1][j]);
    }
    cout << ans << endl;
}

