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

char b[2002][2002];
int l[2002][2002];
int r[2002][2002];
int d[2002][2002];
int u[2002][2002];

int main(){
    int H, W;
    cin >> H >> W;
    rep(i, 0, H+2){
        rep(j, 0, W+2){
            l[i][j] = -1;
            r[i][j] = -1;
            d[i][j] = -1;
            u[i][j] = -1;
        }
    }

    rep(i, 1, H+1){
        string s;
        cin >> s;
        for(int k=0; k<s.length(); k++){
            int j = k+1;
            b[i][j] = s[k];
        }
    }

    rep(row, 1, H+1){
        rep(col, 1, W+1){
            if(b[row][col] == '#') continue;
            l[row][col] = l[row][col-1] + 1;
            u[row][col] = u[row-1][col] + 1;
        }
    }
    for(int row=H; row>=1; row--){
        for(int col=W; col>=1; col--){
            if(b[row][col] == '#') continue;
            r[row][col] = r[row][col+1] + 1;
            d[row][col] = d[row+1][col] + 1;
        }
    }
    int ans = 0;
    rep(row, 1, H+1){
        rep(col, 1, W+1){
            int su = l[row][col] + r[row][col] + u[row][col] + d[row][col] + 1;
            /*
            DEBUG(row);
            DEBUG(col);
            DEBUG(l[row][col]);
            DEBUG(r[row][col]);
            DEBUG(u[row][col]);
            DEBUG(d[row][col]);
            DEBUG(su);
            cout << endl;
            */
            ans = max(ans, su);

        }
    }
    cout << ans << endl;
    return 0;
}


