#include "bits/stdc++.h"
#define DEBUG(x) cout<<#x<<": "<<x<<endl;
#define DEBUG_VEC(v) cout<<#v<<":";for(int i=0;i<v.size();i++) cout<<" "<<v[i cout<<endl
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
typedef long long ll;
const int inf = 1000000001;
const ll INF = 1e18 * 4;
using namespace std;

int dp[1<<22];
int main(){
    int N;
    int a[22][22];
    cin >> N;
    rep(i, 0, N){
        rep(j, 0, N){
            cin >> a[i][j];
        }
    }
    dp[0] = 1;
    for(int bit=0; bit<(1<<N); bit++){
        int guy_ix = __builtin_popcount(bit) - 1;
        for(int i=0; i<N; i++){
           int woman_mask = (1<<i);
           int woman_participating = woman_mask & bit;
           if(woman_participating){
               dp[bit] += (dp[bit ^ woman_mask] * a[guy_ix][i]) % MOD;
               dp[bit] %= MOD;
           }
        }
    }
    cout << dp[(1<<N)-1] << endl;
    return 0;
}


