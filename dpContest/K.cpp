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

bool dp[100001];

int main(){
    int N, K;
    cin >> N >> K;
    int a[101];
    rep(i, 0, N){ cin >> a[i]; }
    // 必ず負ける = true
    dp[0] = true;
    string ans = "First";
    rep(k, 1, K+1){
        bool lose = true;
        rep(j, 0, N){
            bool a_lose;
            if (k >= a[j]){ a_lose = !dp[k-a[j]]; }
            else a_lose = true;
            lose = lose && a_lose;
        }
        dp[k] = lose; 
    }
    if(dp[K]) ans = "Second";
    cout << ans;
}

/*
int dp[100001][2];

int counterpart(int p){
    return abs(1 - p);
}

int get_winner(int k, int p, int* a, int n){
    if(dp[k][p] != -1){
        return dp[k][p];
    }
    int winner = counterpart(p);
    rep(i, 0, n){
        if(k==a[i]){ winner = p; }
        else if(k - a[i] > 0){
            if(get_winner(k-a[i], counterpart(p), a, n) == p){
                winner = p;
            }
        }
    }
    dp[k][p] = winner;
    return dp[k][p];
}

int main(){
    int N, K;
    cin >> N >> K;
    int a[101];
    rep(i, 0, N){ cin >> a[i]; }

    rep(i, 0, K+1){
        rep(p, 0, 2){
            dp[i][p] = -1;
        }
    }
    string ans = "First";
    if(get_winner(K, 0, a, N) == 1){ ans = "Second"; }
    cout << ans;
    return 0;
}
*/

