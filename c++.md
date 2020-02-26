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


## C++
### 役立つもの
- [c++のvector](https://qiita.com/ysuzuki19/items/df872d91c9c89cc31aee)
