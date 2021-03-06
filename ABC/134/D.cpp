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

vi decompose(int i){
    vi ans;
    for(int j=1; j<(int)sqrt(i) + 1; j++){
        if(i % j == 0){
            ans.push_back(j);
            if((int)(i / j) != j) ans.push_back(i / j);
        }
    }
    return ans;
}

int main(){
    int N; cin >> N;
    vi a;
    vi b(N+1, 0);
    vi box(N+1, 0);
    rep(i, 0, N){
        int x;
        cin >> x;
        a.push_back(x);
    }
    for(int i=N; i>0; i--){
        if((a[i-1] == 1 && b[i] % 2 == 0) || (a[i-1] == 0 && b[i] % 2 == 1)){
            b[i] += 1;
            box[i] += 1;
            vi yakusu = decompose(i);
            for(auto &j : yakusu){
                if(j == i) continue;
                b[j] += 1;
            }
        }
    }
    ll cnt = accumulate(box.begin(), box.end(), 0LL);
    cout << cnt << endl;
    rep(i, 1, N+1){
        if(box[i]) cout << i << endl;
    }
    return 0;
}


