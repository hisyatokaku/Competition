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

int N = 100001;

vector<bool> prime(N, true);

void fillPrime(){
    prime[0] = false;   
    prime[1] = false;
    ll N = prime.size();
    for(ll i=2; i<N; i++){
        if(!prime[i]) continue;
        if(prime[i]){
            ll num = i << 1;
            while(num < N){
                prime[num] = false;
                num += i;
            }
        }
    }
}

int main(){
    int Q; cin >> Q;
    fillPrime();
    vi like2017(N, 0);
    rep(i, 1, N){
        if(i % 2 == 0) continue;
        if(prime[i] && prime[(i+1)/2]) like2017[i]++;
    }
    vi cumsum(N+1, 0);
    rep(i, 0, N){
        cumsum[i+1] = cumsum[i] + like2017[i];
    }
    
    vi L;
    vi R;
    rep(i, 0, Q){
        int l, r;
        cin >> l >> r;
        L.push_back(l);
        R.push_back(r);
    }
    rep(i, 0, Q){
        ll l = L[i];
        ll r = R[i];
        cout << cumsum[r+1] - cumsum[l] << endl;
    }

    return 0;
}


