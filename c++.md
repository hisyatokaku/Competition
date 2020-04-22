## syntax上の注意
- 入力にもlong longを使おう
- リテラルにはLLをつけないとintとして解釈されてしまう。
  - 例えば1LL << 63とする必要がある。1 << 63ではinteger扱いにされる。

## Adjacency Matrixの入力例
```cpp
using edge = struct{ll to; ll dist;}
vector<vector<edge> > G(n);
G[0].push_back({to; dist;});
```

## for文ループ
```cpp
for(auto &v : vector){
  do_something();
}
```

## nCr
```cpp
// https://drken1215.hatenablog.com/entry/2018/06/08/210000
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

COMinit();
```

# グラフ
## dijkstra
```cpp
using edge = struct{ll to; ll dist;};
vector<vector<edge>> G(N);

vi dijkstra(int v){
    vi d(N, inf);
    d[v] = 0;
    priority_queue<pii, vector<pii>, greater<pii> > que;
    que.push({v, 0});
    while(!que.empty()){
        pii cur = que.top(); que.pop();
        for(auto &p : G[cur.first]){
            if(d[p.to] > d[cur.first] + p.dist){
                d[p.to] = d[cur.first] + p.dist;
                que.push({p.to, d[p.to]});
            }
        }
    }
    return d;
}

```

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
### Priority-Queue
```cpp
priority_queue<int> max_heap; 
priority_queue<int, vector<int>, greater<int> > min_heap;
// pythonと逆でデフォルトがmax-heapなので注意
```


### Union-Find
```cpp
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

## 算数
### 非常に長い数が入った文字列のmod
左から10をかけていく。

```cpp
int modp = 0;
rep(i, 0, N){
  modp *= 10;
  modp += (s[i] - '0');
  modp %= p;
}
```

### 非常に長い数を10進数に直す
```cpp
int n = 0;
rep(i, 0, N){
  n *= 10;
  n += (s[i] - '0');
}
```
## C++
### 役立つもの
- [c++のvector](https://qiita.com/ysuzuki19/items/df872d91c9c89cc31aee)
- [STL使用例](http://www-ikn.ist.hokudai.ac.jp/~kida/lecture/D_hokudai_Library.pdf)
