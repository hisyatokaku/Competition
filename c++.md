# 素数
## エラトステネス
```cpp
  ll N = (TODO);
  vector<bool> prime(N, true);

  void fillPrime(){
      prime[0] = false;
      prime[1] = false;
      ll N = prime.size();
      for(ll i=2; i<N; i++){
          if(!prime[i]) continue;
          if(prime[i]){
              ll num = i << 1;
              while(num < N){
                  prime[num] = false;
                  num += i;
              }
          }
      }
  }
```

### Union-Find
```cpp
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

```

## C++
### 役立つもの
- [c++のvector](https://qiita.com/ysuzuki19/items/df872d91c9c89cc31aee)
- [STL使用例](http://www-ikn.ist.hokudai.ac.jp/~kida/lecture/D_hokudai_Library.pdf)
