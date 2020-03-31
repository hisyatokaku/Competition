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
 
vii G(100001, vi());
 
int dist_1_N = 0;
vi reachable(2, 0);
int N;
unordered_set<int> paths;
vi parent(100001, -1);
vi visited(100001, 0);
 
void dfs(int v, int par=-1){
    parent[v] = par;	
	for(auto &next_v : G[v]){
        if(par == next_v) continue;
        dfs(next_v, v);		
	}
}

void one_to_n_bfs(){
    queue<pii> q;
    q.push(make_pair(0, 0));
    q.push(make_pair(1, N-1));
    visited[0] = 1;
    visited[N-1] = 1;
    while(!q.empty()){
        int player = q.front().first;
        int cur_v = q.front().second;
        q.pop();
        for(auto &next_v : G[cur_v]){
            if(visited[next_v]) continue;
            if(paths.find(next_v) != paths.end()){
                reachable[player]++;
                cout << endl;
                q.push(make_pair(player, next_v));
                visited[next_v] = 1;
            }
        }
    }
}

void other_dfs(int player, int v){
    visited[v] = 1;
    reachable[player]++;
    for(auto &next_v : G[v]){
        if(player==0 && next_v == N-1) continue;
        if(player==1 && next_v == 0) continue;
        if(visited[next_v]) continue;
        other_dfs(player, next_v);
    }
}

void add_paths(int v, int par=-1){
    if(v == 0 || v == N-1) return;
    paths.insert(v);
    for(auto &next_v : G[v]){
        if(par == next_v) continue;
        add_paths(next_v, v);
    }
}
 
int main(){
    cin >> N;
    rep(i, 0, N-1){
        int a, b; cin >> a >> b;
        a--; b--;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    dfs(0, -1);
    int next_par = N-1;
    while(next_par > 0){
        paths.insert(next_par);
        next_par = parent[next_par]; 
    }
    paths.erase(N-1);
    if(!paths.empty()){
        int v = *paths.begin();
        add_paths(v);
    }
    one_to_n_bfs();
    other_dfs(0, 0);
    other_dfs(1, N-1);

    string winner = "Fennec";
    if(reachable[0] <= reachable[1]) winner = "Snuke";
    cout << winner << endl;
    return 0;
}

