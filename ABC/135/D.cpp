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
ll dp[1000002][13];
int main(){
    string s; cin >> s;
    int N = s.length();
    /*
    dp[0][0] = 1;
    for(int i=0; i<N; i++){
        int digit = s[i] - '0';
        for(int j=0; j<13; j++){
            if(s[i] == '?'){
                for(int k=0; k<10; k++){
                    int new_mod = (10 * j + k) % 13;
                    dp[i+1][new_mod] += dp[i][j];
                    dp[i+1][new_mod] %= MOD;
                }
            } else {
                    int new_mod = (10 * j + digit) % 13;
                    dp[i+1][new_mod] += dp[i][j];
                    dp[i+1][new_mod] %= MOD;
            }
        }
    }
    cout << dp[N][5] << endl;
    */
    for(int j=0; j<13; j++){
        if(s[0] == '?'){
            for(int k=0; k<10; k++){
                int new_mod = k % 13;
                dp[0][new_mod] = 1;
            }
        }
        else {
            int new_mod = (s[0] - '0') % 13;
            dp[0][new_mod] = 1;
        }
    }

    for(int i=1; i<N; i++){
        for(int j=0; j<13; j++){
            if(s[i] == '?'){
                for(int k=0; k<10; k++){
                    int new_mod = (j * 10 + k) % 13;
                    dp[i][new_mod] += dp[i-1][j];
                    dp[i][new_mod] %= MOD;
                }
            } else {
                int new_mod = j * 10 + (s[i] - '0');
                new_mod %= 13;
                dp[i][new_mod] += dp[i-1][j];
                dp[i][new_mod] %= MOD;
            }
        }
    }
    cout << dp[N-1][5] % MOD << endl;
    return 0;
}


