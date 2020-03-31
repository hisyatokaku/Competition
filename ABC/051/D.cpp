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
const int inf = 10001;
const ll INF = 1e18 * 4;
using namespace std;

int main(){
    int N, M; cin >> N >> M;
    vii G(N, vi(N, inf));
    vii d(N, vi(N, inf));
    
    rep(i, 0, M){
        int a, b, c; cin >> a >> b >> c;
        a--; b--;
        G[a][b] = c;
        G[b][a] = c;
        d[a][b] = c;
        d[b][a] = c;
    }
    rep(i, 0, N){
        G[i][i] = 0;
        d[i][i] = 0;
    }
    rep(k, 0, N){
        rep(i, 0, N){
            rep(j, 0, N){
                d[i][j] = min(d[i][j], d[i][k] + d[k][j]); 
            }
        }
    }
    ll ans = 0;
    rep(a, 0, N){
        rep(b, 0, N){
            int dist = G[a][b];
            bool used = false;
            if(dist == inf) continue;
            if(a == b) continue;
            rep(i, 0, N){
                rep(j, 0, N){
                    if(d[i][a] + dist + d[b][j] == d[i][j]) used = true;
                }
            }
            if(!used) ans++;
        }
    }
    cout << (int)(ans / 2) << endl;
    return 0;
}


