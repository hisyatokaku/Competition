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
    int H, W; cin >> H >> W;
    int N; cin >> N;
    vi a(N);
    vii G(H, vi(W));
    rep(i, 0, N) cin >> a[i];
    int cur_i = 0;
    rep(r, 0, H){
        if(r % 2 == 0){
            for(int c=0; c<W; c++){
                if(a[cur_i] == 0) cur_i++;
                G[r][c] = (cur_i + 1);
                a[cur_i]--;
            } 
        } else {
            for(int c=W-1; c >= 0; c--){
                if(a[cur_i] == 0) cur_i++;
                G[r][c] = (cur_i + 1);
                a[cur_i]--;
            } 
        }

    }
    rep(i, 0, H){
        rep(j, 0, W){
            cout << G[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}


