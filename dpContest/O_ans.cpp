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
    int a[21][21];
    // should be 1<<21 w/o overflow
    ll dp[1<<19];
    int N; cin >> N;
    rep(i, 0, N){
        rep(j, 0, N){
            cin >> a[i][j];
        }
    }
    dp[0] = 1;
    for(int bit=0; bit < (1<<N); bit++){
        int pos = __builtin_popcount(bit) - 1; // pos: num of participants 
        for(int i=0; i<N; i++){ // i: guy index
            cout << "bit=" << bitset<3>(bit) << ", 1<<i = " << (1<<i) << ", bit & (1<<i)=" << bitset<3>(bit&(1<<i)) << ", bit^(1<<i)=" << bitset<3>(bit^(1<<i)) << endl;
            if((bit & (1 << i)) && a[pos][i]){
                dp[bit] += dp[bit ^ (1 << i)];
                cout << "dp[" << bitset<3>(bit) << "]" << " += dp[" << bitset<3>(bit^(1<<i)) << "]" << endl;
                dp[bit] %= MOD; 
            }
        }
        cout << endl;
    }
    cout << dp[(1<<N) - 1] << endl;

    return 0;
}


