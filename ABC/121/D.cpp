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

vl offset(48, 0);

vl countOneEachBit(ll n){
    ll d = 0;
    ll cp_n = n;
    while(cp_n > 0){
        cp_n = floor(cp_n/2); 
        d++;
    }
    vl ans(48, 0);
    rep(i, 0, d){
        ll p = (n - offset[i]) / (1LL << i);
        ll q = (n - offset[i]) % (1LL << i);
        if(i == 0){
            if(ll(floor((p+1))/2) % 2 == 1){
                ans[i] = 1;
            }
            continue;
        }
        if(p % 2 == 0){
            if(q % 2 == 1){
                ans[i] = 1;
            }
        }
    }
    return ans;
}

int main(){
    ll A, B; cin >> A >> B;
    rep(i, 0, 48){
        offset[i] = (1LL << i) - 1;
    }
    vl count1 = countOneEachBit(B);
    vl count2 = countOneEachBit(A-1);
    ll ans = 0;
    rep(i, 0, 48){
        ll s = 1LL << i;
        if((count1[i] + count2[i]) % 2 > 0) ans += (1LL << i);
    } 
    cout << ans << endl; 
}
