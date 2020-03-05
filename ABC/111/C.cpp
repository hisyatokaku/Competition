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
    int a[100001];
    int n; cin >> n;
    map<int, int, greater<int> > odd_count;
    map<int, int, greater<int> > even_count;
    rep(i, 0, n){
        cin >> a[i];
        if(i % 2 == 0){
            even_count[a[i]]++;
        } else {
            odd_count[a[i]]++;
        }
    }
    int ans = inf;
    map<int, int>::iterator it;
    map<int, int>::iterator jt;
    for(it=even_count.begin(); it != even_count.end(); it++){
        DEBUG(it->first);
    }
    DEBUG(1);
    for(auto i = odd_count.begin(); i != odd_count.end() && i != next(odd_count.begin(), 2); i++){
        for(auto j=even_count.begin(); j != even_count.end() && j != next(even_count.begin(), 2); j++){
            int arrSize = odd_count.size();
            int okey = i->first;
            int okeyCount = i->second;
            int ekey = j->first;
            int ekeyCount = j->second;
            DEBUG(okey);
            DEBUG(ekey);
            if(okey == ekey) continue;
            ans = min(ans, (arrSize - okeyCount) + (arrSize - ekeyCount));
            
        }
    }
    cout << ans << endl;
    return 0;
}


