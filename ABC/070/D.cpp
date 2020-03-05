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
#define vpll vector< vector<pll> >
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

using edge = struct{ll to; ll dist;};

int n = 100001;
vector<vector<edge> > G(n);
vl d(n, -1);

void dfs(int v, ll dist, int par=-1){
    for(auto &e : G[v]){
        int next_v = e.to;
        if(par == next_v) continue;
        if(d[next_v] > -1) continue;
        ll next_dist = dist + e.dist;
        d[next_v] = next_dist;
        dfs(next_v, next_dist, v);
    } 
    return;
}

int main(){
    int N; cin >> N;
    rep(i, 0, N-1){
        ll a, b, c;
        cin >> a >> b >> c;
        a--; b--; 
        G[a].push_back({b, c});
        G[b].push_back({a, c});
    }
    int Q, K; cin >> Q >> K;
    K--;
    vi X;
    vi Y;
    rep(i, 0, Q){
        ll x, y;
        cin >> x >> y;
        x--; y--;
        X.push_back(x);
        Y.push_back(y);
    }
    d[K] = 0LL;
    dfs(K, 0, -1);
    rep(i, 0, Q){
        int x = X[i];
        int y = Y[i];
        cout << llabs(d[K] - d[x]) + llabs(d[K] - d[y]) << endl;
    }
    return 0;
}
