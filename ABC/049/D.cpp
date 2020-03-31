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

struct UnionFind{
    vi parents;
    UnionFind(int N): parents(N){
        rep(i, 0, N) parents[i] = -1;
    }
    int find(int x){
        if(parents[x] < 0) return x;
        return parents[x] = find(parents[x]);
    }
    bool unite(int x, int y){
        int root_x = find(x);
        int root_y = find(y);
        if(root_x == root_y) return false;
        if(size(root_x) < size(root_y)) swap(root_x, root_y);
        parents[root_x] += parents[root_y];
        parents[root_y] = root_x;
        return true;
    }
    int size(int x){
        return -parents[find(x)];
    }
    bool same(int x, int y){
        return find(x) == find(y);
    }
};

int main(){
    int N, K, L; cin >> N >> K >> L;
    UnionFind uf1(N);
    vi P; 
    vi Q;
    rep(i, 0, K){
        int a, b; cin >> a >> b;
        a--; b--;
        P.push_back(a);
        Q.push_back(b);
        uf1.unite(a, b);
    }
    UnionFind uf2(N);
    vi A;
    vi B;
    rep(i, 0, L){
        int a, b; cin >> a >> b;
        a--; b--;
        A.push_back(a);
        B.push_back(b);
        uf2.unite(a, b); 
    }
    UnionFind uf3(N);

    rep(i, 0, K){
        int a = P[i];
        int b = Q[i];
        if(uf1.same(a, b) && uf2.same(a, b)) uf3.unite(a, b);
    }

    rep(i, 0, L){
        int a = A[i];
        int b = B[i];
        if(uf1.same(a, b) && uf2.same(a, b)) uf3.unite(a, b);
    } 

    rep(i, 0, N){
        cout << uf3.size(i) << " ";
    }
    cout << endl;
    return 0;
}


