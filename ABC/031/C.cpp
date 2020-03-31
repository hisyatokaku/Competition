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
    int N; cin >> N;
    vi a;
    rep(i, 0, N){
        int _a; cin >> _a;
        a.push_back(_a);
    }
    int ans = -inf;
    rep(i, 0, N){
        int aoki_j = -1;
        int max_aoki = -inf;
        int max_taka = -inf;
        rep(j, 0, N){
            if(i==j) continue;
            int aoki = 0;
            int taka = 0;
            for(int di=0; min(i, j) + di <= max(i, j); di++){
                int c = min(i, j) + di;
                if((di + 1) % 2 == 0){
                    aoki += a[c];
                } else {
                    taka += a[c]; 
                } 
            }
            if(max_aoki < aoki){
                max_aoki = aoki;
                max_taka = taka;
                aoki_j = j;
            }
        }
        ans = max(max_taka, ans);
    }
    cout << ans << endl;

    return 0;
}


