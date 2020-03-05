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
#define maxN 100001
vii G(maxN, vi());

int memo[maxN];

int longestPath(int i){
    int ans = 0;
    if(memo[i] >= 0) return memo[i];
    int childLen = G[i].size();
    if(childLen){
        for(int j=0; j<childLen; j++){
            ans = max(ans, 1 + longestPath(G[i][j]));
        }
    }
    memo[i] = ans;
    return ans;
}

int main(){
    int N, M;
    cin >> N >> M;
    rep(i, 0, M){
        int x, y; cin >> x >> y;
        x--; y--;
        G[x].push_back(y);
    }
    rep(i, 0, maxN) memo[i] = -1;
    int ans = 0;
    rep(i, 0, N) ans = max(ans, longestPath(i));
    cout << ans << endl;
    return 0;
}


