### Knapsack

### LIS
dp[i]: 長さがi+1になるようなLISの最後の値として考えられる最小値
各ループでのdpテーブルの更新は一つのインデックスにしか起こらない。
```
vi a;
vi dp(N, inf);
rep(i, 0, h_v.size()){
    auto it = lower_bound(dp.begin(), dp.end(), a[i]);
    *it = a[i]; // update
}
int ans = 0;
rep(i, 0, N){
    if(dp[i] < inf) ans = i+1;
}
return ans;
```
