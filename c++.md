## syntax上の注意
- 入力にもlong longを使おう
- リテラルにはLLをつけないとintとして解釈されてしまう。
  - 例えば1LL << 63とする必要がある。1 << 63ではinteger扱いにされる。

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
