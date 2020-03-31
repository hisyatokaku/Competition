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

int dp[42][402][402];

int main(){
    rep(i, 0, 42){
        rep(j, 0, 402){
            rep(k, 0, 402){
                dp[i][j][k] = inf;
            } 
        }
    }
    int N, ma, mb; cin >> N >> ma >> mb;
    vi a;
    vi b;
    vi c;
    rep(i, 0, N){
        int p, k, l; cin >> p >> k >> l;
        a.push_back(p);
        b.push_back(k);
        c.push_back(l);
    }
    rep(i, 0, N+1){
        dp[i][0][0] = 0;
    }
    rep(i, 0, N){
        rep(j, 0, 402){
            rep(k, 0, 402){
                if(j-a[i] >= 0 && k-b[i] >= 0){
                    dp[i+1][j+a[i]][k+b[i]] = min(dp[i+1][j+a[i]][k+b[i]], dp[i][j][k] + c[i]);
                } else {
                    dp[i+1][j+a[i]][k+b[i]] = dp[i][j][k];
                }
            }
        }
    }
    int ans = inf;
    rep(j, 0, 402){
        rep(k, 0, 402){
            if(j==0 && k == 0) continue;
            if(j * mb == k * ma){
                ans = min(ans, dp[N][j][k]);           
            }
        }
    }
    /* rep(i, 0, 4){ */
    /*     cout << i << endl; */
    /*     rep(j, 0, 10){ */
    /*         rep(k, 0, 10){ */
    /*             cout << dp[i][j][k] << " "; */
    /*         } cout << endl; */
    /*     } */
    /*     cout << endl; */
    /* } */
    if(ans == inf) cout << "-1" << endl;
    else cout << ans << endl;

    return 0;
}


