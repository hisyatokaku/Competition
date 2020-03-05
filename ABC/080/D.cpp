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
    ll N, C; cin >> N >> C;
    ll T = 100000;
    vl now(2*T+1, 0);
    vll cnt(C, vl(T+1, 0));
    rep(i, 0, N){
        ll s, t, c;
        cin >> s >> t >> c;
        c--;
        cnt[c][s] += 1;
        cnt[c][t] -= 1;
    }
    rep(c, 0, C){
        rep(i, 0, T){
            cnt[c][i+1] += cnt[c][i];
        }
    }
    rep(c, 0, C){
        rep(i, 1, T+1){
            if(cnt[c][i-1] == 0 && cnt[c][i] > 0){
                now[2*i-1] += 1;
            }
            if(cnt[c][i-1] > 0 && cnt[c][i] == 0){
                now[2*i] += (-1);
            }
        }
    }
    rep(i, 0, 2*T){
        now[i+1] += now[i];
    }
    cout << *max_element(now.begin(), now.end()) << endl;
    return 0;
}


