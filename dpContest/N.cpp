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

int main() {
    int N;
    cin >> N;
    int a[401];
    rep(i, 0, N) cin >> a[i];

    ll cumsum[402];
    cumsum[0] = 0;
    rep(i, 0, N) cumsum[i+1] = cumsum[i] + a[i];
    rep(i, 0, N+1) cout << cumsum[i] << " ";
    cout << endl;
    cout << endl;

    ll dp[401][401];
    rep(i, 0, N+1){
        rep(j, 0, N+1){
            dp[i][j] = INF;
        }
    }
    rep(i, 0, N+1) dp[i][i] = 0;
    rep(i, 0, N) dp[i][i+1] = 0;
    rep(k, 2, N+1){
        for(int i=0; i<N+1; i++){
            int j = i + k;
            if(j > N) continue;
            for(int l=i+1; l<j; l++){
                dp[i][j] = min(dp[i][j], dp[i][l] + dp[l][j] + cumsum[j] - cumsum[i]);
            }
        }
    }
    rep(i, 0, N+1){
        rep(j, 0, N+1){
            cout << dp[i][j] << " ";
        }
        cout << endl;
    }
    cout << dp[0][N] << endl;

    return 0;
}


