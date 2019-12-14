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

int g[100001][3];
int dp[100001][3];

int main(){
    int N; cin >> N;
    rep(i, 0, N){
        int a, b, c;
        cin >> a >> b >> c;
        g[i][0] = a; g[i][1] = b; g[i][2] = c;
    }
    dp[0][0] = g[0][0];
    dp[0][1] = g[0][1];
    dp[0][2] = g[0][2];
    for(int i=1; i<N; i++){
        dp[i][0] = max(dp[i-1][1] + g[i][0], dp[i-1][2] + g[i][0]);
        dp[i][1] = max(dp[i-1][0] + g[i][1], dp[i-1][2] + g[i][1]);
        dp[i][2] = max(dp[i-1][0] + g[i][2], dp[i-1][1] + g[i][2]);
    }
    cout << max(max(dp[N-1][0], dp[N-1][1]), dp[N-1][2]) << endl;

    return 0;

}


