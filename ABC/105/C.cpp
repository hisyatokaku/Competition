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

vl pow2neg(36, 1);
int main(){
    rep(i, 1, 36){
        pow2neg[i] = pow2neg[i-1] << 1;
        pow2neg[i] *= (-1);
    }
    ll N; cin >> N;
    if(N==0){
        cout << "0" << endl;
        return 0;
    }
    N--;
    bool pos = N > 0;
    int k = 1;
    int cpN = N > 0 ? N: -N;
    while(cpN > 1){
        cpN = floor(cpN/2); 
        k += 1;
    }
    if(pos){
        if(k % 2 == 0) k++;
    } else {
        if(k % 2 != 0) k++;
    }
    DEBUG(k);
    N++;
    int i=0;
    while(i < 1 << (k-1)){
        ll cand = 1;
        rep(j, 0, k-1){
            if(i >> j & 1){
                cand += pow2neg[k-1-j];
            }
        }
        if(cand == N) break;
        i++;
    }
    for(int j=0; j<=k-2; j++){
        if(i >> j & 1) cout << "1";
        else cout << "0";
    }
    cout << "1";
    return 0;
}


