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
    int N, K; cin >> N >> K;
    vl a(N);
    rep(i, 0, N) cin >> a[i];
    // index a[i+1]までみて和がjになる組の数があるときdp[i][j] = 1, ないなら0
    vii fdp(N+1, vi(K+1, 0));
    fdp[0][0] = 1;
    // index a[N-1]からa[N-i]までみて和がjになる組があるならdp[i][j] = 1, ないなら0
    vii bdp(N+1, vi(K+1, 0));
    vii cumsum(N+1, vi(K+2, 0));
    bdp[0][0] = 1;

    rep(i, 0, N){
        rep(j, 0, K+1){

            if(j - a[i] >= 0){
                fdp[i+1][j] = fdp[i][j] || fdp[i][j - a[i]];
            } else {
                fdp[i+1][j] = fdp[i][j];
            }

            if(j - a[N-i-1] >= 0){
                bdp[i+1][j] = bdp[i][j] || bdp[i][j - a[N-i-1]];
            } else {
                bdp[i+1][j] = bdp[i][j];
            }
        }
    }
    rep(i, 0, N+1){
        rep(j, 0, K+1){
            cout << fdp[i][j] << ", "; 
        }
        cout << endl;
    }
    cout << endl;
    rep(i, 0, N+1){
        rep(j, 0, K+1){
            cout << bdp[i][j] << ", "; 
        }
        cout << endl;
    }
    cout << endl;
    rep(i, 0, N){
        rep(j, 0, K+1){
            // a[i]を抜いたときにfdp[i][fk]とbdp[N-i-1][bk]の和suが
            // K-a[i] <= su <= K-1となるものがあったらアウト
            // この情報をcumsum[i+1]にいれる
            if(fdp[i][j] > 0) cumsum[i+1][j]++;
            if(bdp[N-i-1][j] > 0) cumsum[i+1][j]++;
        }
    }

    rep(i, 0, N+1){
        rep(j, 0, K+1){
            cumsum[i][j+1] += cumsum[i][j];
        }
    }

    ll cnt = 0;
    cout << "cumsum: " << endl;
    rep(i, 0, N+1){
        rep(j, 0, K+1){
            cout << cumsum[i][j] << ", "; 
        }
        cout << endl;
    }
    rep(i, 0, N){
        ll r = K-1;
        ll l = max(0LL, K-a[i]-1);
        DEBUG(i);
        cout << "i: " << i << " l: " << l << " r: " << r << endl;
        DEBUG(cumsum[i+1][r]);
        DEBUG(cumsum[i+1][l]);
        ll rem = cumsum[i+1][r] - cumsum[i+1][l];
        if(rem == 0) cnt++;
        cout << endl;
    }
    cout << cnt << endl;
    return 0;
}


