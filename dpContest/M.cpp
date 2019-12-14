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
    int N, K;
    cin >> N >> K;
    int a[101];
    rep(i, 0, N) cin >> a[i];
    int** dp = new int*[102];
    rep(i, 0, 102){
        dp[i] = new int[100001];
    }
    rep(k, 1, 100001) dp[N][k] = 0;
    rep(i, 0, 102) dp[i][0] = 1;

    for(int k=0; k<=K; k++){
        for(int i=N; i>=0; i--){
            if(k - a[i] < 0){
                dp[i][k+1] = (dp[i][k] + dp[i+1][k+1]) % MOD;
            } else{
                dp[i][k+1] = (dp[i][k] + dp[i+1][k+1] - dp[i+1][k-a[i]])%MOD;
            }
        }
    }

    cout << dp[0][K] << endl;
    rep(i, 0, 102) delete[] dp[i];
    delete[] dp;
    return 0;
}
