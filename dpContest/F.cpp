#include "bits/stdc++.h"
#define DEBUG(x) cout<<#x<<": "<<x<<endl;
#define DEBUG_VEC(v) cout<<#v<<":";for(int i=0;i<v.size();i++) cout<<" "<<v[i]; cout<<endl

#define vl vector<ll>
#define vii vector< vector<int> >
#define vll vector< vector<ll> >
#define vs vector<string>
#define pii pair<int,int>
#define pis pair<int,string>
#define psi pair<string,int>
#define pll pair<ll,ll>
#define rep(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))
#define pipii pair<int, pair<int, int> >
#define MOD 1000000007
#define mod 1000000009
#define pi 3.14159265358979323846
#define Sp(p) cout<<setprecision(15)<< fixed<<p<<;
int dx[4] = { 1,0,-1,0 }, dy[4] = { 0,1,0,-1 };
int dx2[8] = { 1,1,0,-1,-1,-1,0,1 }, dy2[8] = { 0,1,1,1,0,-1,-1,-1 };
typedef long long ll;
const int inf = 1000000001;
const ll INF = 1e18 * 4;
using namespace std;
#define N 3001
pipii dp[N][N];
// dp[i][j]: len(LCS(s[:i], t[:j]))
int main(){
    string ans = "";
    string s, t;
    cin >> s;
    cin >> t;
    rep(i, 0, N){
        dp[i][0] = pipii(0, pii(-1, -1));
        dp[0][i] = pipii(0, pii(-1, -1));
    }
    // どこから遷移したのか考える
    rep(i, 0, s.length()){
        rep(j, 0, t.length()){
            if(s[i] == t[j]){
                dp[i+1][j+1] = pipii(dp[i][j].first + 1, pii(i, j));
            } else {
                dp[i+1][j+1] = dp[i][j+1].first > dp[i+1][j].first ? 
                    dp[i][j+1] : dp[i+1][j];
                    /* pipii(dp[i][j+1].first, pii(i, j+1)) : */ 
                    /* pipii(dp[i+1][j].first, pii(i+1, j)); */
            }
        }
    }
    int i = dp[s.length()][t.length()].second.first;
    int j = dp[s.length()][t.length()].second.second;

    while (i >= 0 && j >= 0){
        ans += s[i];
        pipii tmp = dp[i][j];
        i = tmp.second.first;
        j = tmp.second.second;
    }
    /* rep(i, 0, s.length()+1){ */
    /*     rep(j, 0, t.length()+1){ */
    /*         cout << "(" << dp[i][j].second.first << ", " << dp[i][j].second.second << ") "; */
    /*     } */
    /*     cout << endl; */
    /* } */
    reverse(ans.begin(), ans.end());
    cout << ans << endl;

    return 0;
}


