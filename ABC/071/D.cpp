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
    vii G(52, vi(52, 0));
    int N; cin >> N;
    string S1, S2;
    cin >> S1;
    cin >> S2;
    rep(i, 0, N){
        int v1 = S1[i] - 'a';
        int v2 = S2[i] - 'a';
        if(v1 != v2){
            G[v1][v2]++;
            G[v2][v1]++;
        }
    }
    rep(i, 0, N-1){
        int v1 = S1[i] - 'a';
        int v2 = S1[i+1] - 'a';
        
        int v3 = S2[i] - 'a';
        int v4 = S2[i+1] - 'a';

        if(v1 != v2){
            G[v1][v2]++;
            G[v2][v1]++;
        }
        if(v3 != v4){
            G[v3][v4]++;
            G[v4][v3]++;
        }
    }

    return 0;
}


