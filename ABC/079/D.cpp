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

vii d(10, vi(10, inf));
vii visited(10, vi(10, 0));
vii c(10, vi(10));

int find_min_v(int cur_v){
    int ans = inf;
    int ans_i = -1;
    cout << "find_min" << endl;
    rep(i, 0, d[0].size()){
        if(visited[cur_v][i]) continue;
        if(ans > d[cur_v][i]){
            ans = d[cur_v][i];
            ans_i = i;
        }
    } 
    return ans_i;
}

void dijkstra(int cur_v){
    d[cur_v][cur_v] = 0;
    /* while(false){ */
    /* //while(find_min_v(cur_v) > -1){ */
    /*     int fr_v = find_min_v(cur_v); */
    /*     visited[cur_v][fr_v] = 1; */
    /*     rep(to_v, 0, 10){ */
    /*         if(d[cur_v][to_v] > (d[cur_v][fr_v] + c[fr_v][to_v])){ */
    /*             d[cur_v][to_v] = d[cur_v][fr_v] + c[fr_v][to_v]; */
    /*         } */
    /*     } */
    /* } */
}

int main(){
    int H, W; cin >> H >> W;
    rep(i, 0, 10){
        rep(j, 0, 10){
            int _c; cin >> _c;
            c[i][j] = _c;
        }
    }
    rep(i, 0, 10){
        DEBUG(i);
        dijkstra(i);
        DEBUG_VEC(d[i]);
    }
    ll cnt = 0;
    rep(i, 0, H){
        rep(j, 0, W){
            int a; cin >> a;
            if(a==-1) continue;
            cnt += d[a][1];
            cout << cnt << endl;
        }
    }
    cout << cnt << endl;
    return 0;
}


