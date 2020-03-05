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
    ll N; cin >> N;
    vll G(N, vl(N));
    vll dp(N, vl(N));
    rep(i, 0, N){
        rep(j, 0, N){
            cin >> G[i][j];
            dp[i][j] = G[i][j];
        }
    }
    rep(i, 0, N){
        rep(j, 0, N){
            rep(k, 0, N){
                if(G[i][j] > G[i][k] + G[k][j]){
                    cout << -1 << endl;
                    return 0;
                }
            }
        }
    }
    rep(i, 0, N){
        rep(j, 0, N){
            rep(k, 0, N){
                if(j==k || i==k) continue;
                if(dp[i][k] == 0 || dp[i][j] == 0 || dp[k][j] == 0) continue;
                if(G[i][j] == G[i][k] + G[k][j]) dp[i][j] = 0;
            }
        }
    }
    ll cnt=0;
    rep(i, 0, N){
        rep(j, 0, N){
            cnt += dp[i][j];
        }
    }
    cout << cnt / 2 << endl;

    return 0;
}


