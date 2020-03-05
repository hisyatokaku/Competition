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
#define ppiii pair<pair<int, int>, int>
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

vs maze;
int H, W;

int solve(int s_r, int s_c, int g_r, int g_c){
    int visited[21][21];
    queue<pis> que;
    pis m (3, "a");
    que.push(m);
}

int main(){
    cin >> H >> W;
    rep(i, 0, H){
        string s; cin >> s;
        maze.push_back(s);
    }
    for(int st_row; st_row<H; st_row++){
        for(int st_col; st_col<W; st_col++){
            for(int g_row; g_row<H; g_row++){
                for(int g_col; g_col<W; g_col++){
                }
            }
        }
    }


    return 0;
}


