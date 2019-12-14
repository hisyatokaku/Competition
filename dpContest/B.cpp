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
    int h[100001];
    cin >> N >> K;
    rep(i, 0, N) cin >> h[i];    
    int dp[100001];
    rep(i, 0, 100001) dp[i] = inf;
    dp[0] = 0;
    for(int i=0; i<N; i++){
        for(int k=1; k<=K; k++){
            if(i-k >= 0){
                dp[i] = min(dp[i], dp[i-k] + abs(h[i] - h[i-k]));
            }
        }
    }
    /*    
    dp[0] = 0;
    for(int i=1; i<N; i++){
        int minCost = dp[i-1] + abs(h[i] - h[i-1]);
        for(int k=1; k<=K; k++){
            if(i-k >= 0){
                minCost = min(minCost, dp[i-k] + abs(h[i] - h[i-k])); 
            }
        } 
        dp[i] = minCost;
    }
    */
    cout << dp[N-1] << endl;
    return 0;
}


