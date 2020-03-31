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



ll s_match(string a, string b){
    ll max_a_b_dup = 0;
    rep(i, 0, a.length()){
        ll cnt = 0;
        if(a[i] == b[0] || b[0] == '?' || a[i] == '?'){
            int cp_i = i;
            rep(j, 0, b.length()){
                if(cp_i >= a.length()) break;
                if(a[cp_i] == b[j] || a[cp_i] == '?') cnt++;
                else{
                    cnt = 0;
                };
                cp_i++;
            }
        }
        max_a_b_dup = max(max_a_b_dup, cnt);
    }
    ll ans = a.length() + b.length() - max_a_b_dup;
    return ans;}
ll match(string a, string b, string c){
    ll ans = s_match(a, b) + s_match(b, c) - b.length();
    return ans;
}
int main(){
    string a, b, c;
    cin >> a;
    cin >> b;
    cin >> c;
    ll ans = min({
    match(a, b, c),
    match(a, c, b),
    match(b, a, c),
    match(b, c, a),
    match(c, a, b),
    match(c, b, a)
    });
    cout << ans << endl;
    
    return 0;
}


