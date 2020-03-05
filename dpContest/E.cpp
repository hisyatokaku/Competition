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
#define maxW 100001
using namespace std;
vi w(101);
vi v(101);
ll dp[101][maxW];
int main(){
    int N, W;
    cin >> N >> W;
    rep(i, 0, N){
        int x, y;
        cin >> w[i] >> v[i];
    }
    rep(i, 0, maxW) dp[0][i] = INF;
    rep(j, 0, N+1) dp[j][0] = 0;
    rep(i, 0, N){
        rep(j, 0, maxW){
            if(j-v[i] >= 0) dp[i+1][j] = min(dp[i][j-v[i]] + w[i], dp[i][j]);
            else dp[i+1][j] = dp[i][j];
        }
    }
    int ans = 0;
    rep(i, 0, N+1){
        rep(j, 0, maxW){
            if(dp[i][j] <= W){
                ans = max(ans, j);
            }
        }
    }
    cout << ans << endl;
    return 0;
}


