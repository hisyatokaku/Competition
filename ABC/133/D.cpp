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
    vi a;
    vi b(N);
    int sumRain = 0;
    int oneToN1 = 0;
    rep(i, 0, N){
        int x;
        cin >> x;
        sumRain += x;
        if(i % 2 == 1){
            oneToN1 += x;
        }
        a.push_back(x);
    }
    sumRain = sumRain / 2;
    int b1 = sumRain - oneToN1;
    b[0] = 2 * b1;
    int curb = b1;
    for(int i=0; i<N-1; i++){
        int ansb = a[i] - curb;
        b[i+1] = 2 * ansb;
        curb = ansb;
    }
    rep(i, 0, N){
        cout << b[i] << " ";
    }
    cout << endl;
    return 0;
}


