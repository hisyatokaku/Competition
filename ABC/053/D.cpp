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
    vi a(N, 0);
    rep(i, 0, N){
        cin >> a[i];
    }
    vi val(100007, 0);
    vi dup;
    vi nondup;
    rep(i, 0, N){
        val[a[i]]++;
    }
    rep(i, 0, val.size()){
        int e = val[i];
        if(e == 1) nondup.push_back(e);
        else if(e > 1) dup.push_back(e);
        else;
    }
    int ans = 0;
    rep(i, 0, dup.size()){
        if(dup[i] == 1){
            ans++;
            continue;
        }
        while(dup[i] > 2){
            dup[i] -= 2; 
        }

        if(dup[i] == 1){
            ans++;
            continue;
        }
        
        int j = i+1;
        bool usenondup = true;
        bool removeddup = false;
        while(j < dup.size()){
            if(dup[j] == 1){
                j++;
                continue;
            }
            dup[j] -= 1;
            dup[i] -= 1;
            ans++;
            usenondup = false;
            break;
        }
        if(!usenondup) continue;
        rep(k, 0, nondup.size()){
            if(nondup[k] == 1) continue;
            nondup[k] -= 1;
            dup[i] -= 1;
            removeddup = true;
        }
        if(removeddup) ans++;
    }
    ans += nondup.size();
    cout << ans << endl;
    return 0;
}


