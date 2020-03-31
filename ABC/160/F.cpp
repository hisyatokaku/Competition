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
const ll Nmax = 2 * 1e5 + 1;
using namespace std;

vl dp(Nmax, 1LL);
vl dp2(Nmax, 1LL);
vii G(Nmax, vi());
int N;

const int MAX = 510000;

long long fac[MAX], finv[MAX], inv[MAX];

// テーブルを作る前処理
void COMinit() {
    fac[0] = fac[1] = 1;
    finv[0] = finv[1] = 1;
    inv[1] = 1;
    for (int i = 2; i < MAX; i++){
        fac[i] = fac[i - 1] * i % MOD;
        inv[i] = MOD - inv[MOD%i] * (MOD / i) % MOD;
        finv[i] = finv[i - 1] * inv[i] % MOD;
    }
}

// 二項係数計算
long long COM(int n, int k){
    if (n < k) return 0;
    if (n < 0 || k < 0) return 0;
    return fac[n] * (finv[k] * finv[n - k] % MOD) % MOD;
}
// cout << COM(100000, 50000) << endl;

ll dfs(int v, int par=-1){
    for(auto &c : G[v]){
        if(c == par) continue;
        dp[v] += dfs(c, v);
    }
    return dp[v];
}

ll dfs2(int v, int par=-1){
    dp2[v] *= fac[(dp[v] - 1)];
    dp2[v] %= MOD;
    for(auto &c : G[v]){
        if(c == par) continue;
        dp2[v] *= (dfs2(c, v) * finv[dp[c]]);
        dp2[v] %= MOD;
    }
    return dp2[v] % MOD;
}

void bfs(int v, int par=-1){
    for(auto &c : G[v]){
        if(c == par) continue;
        ll v_excludes_c = (dp2[v] * fac[dp[c]]) % MOD;
        v_excludes_c *= fac[dp[v] - dp[c] - 1];
        v_excludes_c %= MOD;

        v_excludes_c *= inv[dp2[c]];
        v_excludes_c %= MOD;

        v_excludes_c  *= finv[dp[v]-1];
        v_excludes_c %= MOD;

        /* dp2[c] *= (((((inv[dp[v]-dp[c]] * fac[dp[v] - 1]) % MOD) * finv[dp[c]]) % MOD) * v_excludes_c); */
        /* dp2[c] *= inv[dp[v] - dp[c]]; */
        dp2[c] *= finv[N-dp[c]];
        dp2[c] %= MOD;

        dp2[c] *= fac[N-1];
        dp2[c] %= MOD;

        dp2[c] *= finv[dp[c]];
        dp2[c] %= MOD;

        dp2[c] *= v_excludes_c;
        dp2[c] %= MOD;

        DEBUG(dp2[c]);
        bfs(c, v);
    }
}

int main(){
    COMinit();
    cin >> N;
    rep(i, 0, N-1){
        int a, b; cin >> a >> b;
        a--; b--;
        G[a].push_back(b);
        G[b].push_back(a);
    }

    // 部分木のサイズを入れる
    dfs(0);

    // 0をルートとした時の答えを計算
    dfs2(0);

    rep(i, 0, N){
        cout << dp2[i] << ", ";
    }
    cout << endl;
    // 全方位木DP部分
    bfs(0);

    rep(i, 0, N){
        cout << dp2[i] % MOD << ", ";
    }
    return 0;
}


