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
    int N;
    cin >> N;
    int a[3001];
    rep(i, 0, N) cin >> a[i];
    ll ans = 0;
    ll** dp = new ll*[3001];
    rep(i, 0, 3001){
        dp[i] = new ll[3001];
    }
    rep(st, 0, N){
        dp[st][st] = a[st];
    }
    for(int k=1; k<N; k++){
        for(int st=0; st+k<N; st++){
            int en = st + k;
            dp[st][en] = max(a[st] - dp[st+1][en], a[en] - dp[st][en-1]);
        }
    }
    cout << dp[0][N-1] << endl;
    /*
    rep(i, 0, N){
        rep(j, 0, N){
            cout << dp[i][j] << ", ";
        }
        cout << endl;
    }
    */

    rep(i, 0, 3001) delete[] dp[i];
    delete[] dp;
    return 0;
}


