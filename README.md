#Atcoder

## C++への移行
- 入力にもlong longを使おう

## 区間スケジューリング
始点(終点)を昇順または降順ソート。
保持する値：始点の最大値, 終点の最小値

## 配列aから一個消して残りの最大・最小を求める系

- left[i]: a[0]からa[i]までの条件を満たす値
- right[j]: a[j]からa[N-1]までの条件を満たす値

とすると、
left[i-1], right[i+1]をつかえばa[i]を消した時の値がわかる

```python
left[0] = (初期値)
right[N-1] = (初期値)

for i in range(1, N):
  left[i] = f(left[i-1], a[i])   # (0, N-1], 1からN-1まで
for j in range(N-1)[::-1]:
  right[j] = f(right[j+1], a[j]) # [0, N-1), 0からN-2まで
```

## 素数チェック
エラトステネスの篩。n以下の全ての素数を列挙するには、2からsqrt(n)まで、自分より大きい倍数にFalseをマークして表を埋めていく。

O(nlog(log(n)))でできる。

```python
prime = [True] * (n + 1)
prime[1] = False
# max_range = int(math.sqrt(n)) + 1

for i in range(2, n + 1):
    if not prime[i]:
        continue
    if prime[i]:
        num = i + i
        while num < n:
            prime[num] = False
            num += i
```

## 素因数分解
nを素因数分解するとき、2からsqrt(n)まで試し割りすることを繰り返す。

```python
def integer_factorization(n):
    prime_count = collections.Counter()
    for i in range(2, int(math.sqrt(n)) + 2):
        while n % i == 0:
            n //= i
            prime_count[i] += 1
    if n > 1:
        prime_count[n] += 1
    return prime_count
```

約数全列挙
1からmath.sqrt(N)までループして割り切れるかどうか調べる。
```python
def yakusu(n):
  yakusu = []
  for i in range(1, int(math.sqrt(n))+1):
    if n % i == 0:
      yakusu.append(i)
      if n // i != i:
        yakusu.append(N//i)
  return yakusu

```



## nCm mod p
参考：http://drken1215.hatenablog.com/entry/2018/06/08/210000

```python
fac = [-1] * (10**7+1)
finv = [-1] * (10**7+1)
inv = [-1] * (10**7+1)

fac[0] = fac[1] = 1
finv[0] = finv[1] = 1
inv[1] = 1

def initNCMMod(limit):
    for i in range(2, limit):
        fac[i] = fac[i-1] * i % mod
        inv[i] = mod - inv[mod%i] * (mod // i) % mod
        finv[i] = finv[i-1] * inv[i] % mod

def NCMMod(n, k):
    if n < k:
        return 0
    if (n < 0 or k < 0):
        return 0
    return fac[n] * (finv[k] * finv[n-k] % mod) % mod
```

## 二分探索の境界条件
### パターン1. ng - ok > 1 条件を満たす境界を求める問題
TL;DR **ng - ok > 1**

例：1, 3, 4, 9, 11, ..., 107のうち、Xという条件を満たす最大の数を求める問題

[わかりやすい記事](http://pekoon.hatenablog.com/entry/2015/02/22/221806)

[わかりやすいqiita](https://qiita.com/drken/items/97e37dd6143e33a64c8c)

ok, ngとなる境界を狭めていくイメージ。左側は必ずokの値、右側は必ずngの値がくるようにする。
(配列ならば-1とlen()を使う)
```python
ok = 0
ng = N + 1
while ng - ok > 1: # important
  m = ok + (ng - ok)/2
  if not satisfy(m):
    ng = m
  else:
    ok = m
return ok
```

### パターン2. 与えられた値(ない場合もある)をピンポイントで見つける問題
TL; DR **l <= r**

例：1, 2, 3, ..., 10から5が存在するかどうか確認する問題
```python
# a: [1, 2, 3, ...]
l = 0
r = len(a) - 1
while l <= r: # important
  m = l + (r-l)/2
  if m == X:
    return True
  if m < X:
    r = m - 1
  if m > X:
    l = m + 1
return False
```

**l <= r**にしないと、lとrが同じになり答えを指しているときに、mを計算するためのループが回らなくなってしまう。

# 文字列探索
- naiveな部分文字列マッチ
```
S = 'aetonkreotonkouesr'
T = 'tonkou'
```
のとき、

```
S = 'aetonkreotonkouesr'
              ^
            st_ix

T = 'tonkou'
     ^
     j ->
```
のようにして、
- 開始位置(st_ix)をforloopでscan
- 二つの文字列をst_ix, jで並行scan
する。

このとき、st_ixはSをscanするための**オフセット**としてとらえるとわかりやすい。

```
for st_ix in range(len(S)):
  for j in range(len(T)):
    check(S[st_ix + j] == T[j])
```

# DP
## ナップザック (要素がN個、重さがWまでの制限を守った最大価値を求める。)

パターン
1. dp[i+1][j]: **indexが0以上i以下の要素を使った時の**、重さjを超えない最大価値
```
dp[i+1][j] = max(dp[i][j], dp[i][j - v[i]])  (j - v[i] >= 0)
           or    dp[i][j]
初期条件：
dp[0][j] = 0
```
2. dp[i+1][j]: 価値jを達成する最小の重み
```
dp[i+1][j] = min(...同様)
初期条件：
dp[0][0] = 0, dp[0][0<] = ∞
```

**要素が(i+1)個、重さ制限がjのsub-problem**を考えている。


for-loopは、(dp[i+1]を使った更新式で書くなら)以下の範囲で回す。dp[N][W]が必要になるから。
```
0 <= i < N
0 <= j <= W
```

## bitDP
パターン
1. 集合をビットで表し、各集合の遷移を考える。
条件に合う参加者を[0010011]のインデックスとして表すとすると、
[0010011]は[0010001], [0010010], [0000011]の状態に一人足した状態として考えられるので、
`
dp[0010011] = dp[0010001] * (...) + dp[0010010] * (...) + dp[0000011] * (...)
`
として良い。
左辺のインデックスは右辺の全てのインデックスより大きいため、forループは小から大の方向へ回せば良い。

```
# N: 参加者
dp[1<<N] 
for bit in range(1 << N):
  for j in range(N):
    mask = 1 << j 
    if mask & bit == 0:
      continue
    sub_index = i ^ mask
    dp[bit] += dp[sub_index]
```
上のコードで、例えばbitが0010011の時、0010001, 0010010, 0000011を作りたいとする。
jに関するforループは、右の桁から一つずつ, bitのj桁目が1かどうかを調べ、1だったら、ひっくり返すということをやっている。

参考:[dpContest/O.cpp](https://github.com/hisyatokaku/Competition/blob/master/dpContest/O.cpp)

## 桁dp
dp[i][j][k]: 左からi桁目まで見終わっており、最大値以下であることが確定している時はj=1, そうでないときはj=0, kは自由にカスタムできる条件式

```
# S: ターゲットとなる文字列。めちゃくちゃ長いのでstrにすることが多い
for i in len(S):
  D = S[i] 
  for j in [0, 1]:
    for k in K:
      for d in range(j ? 9 : D): # j=1なら0から9まで好きな数字を試せるが、j=0なら0からDまで。
        newK = (...)
        dp[i+1][j || (d < D - '0')][newK] += dp[i][j][k]
```  

参考:[dpContest/S.cpp](https://github.com/hisyatokaku/Competition/blob/master/dpContest/S.cpp)

# bit全探索
n桁(0ビットからn-1ビットまで)を探索したい
```
for i in (1 << n):
  pass
```

iという数字に対し、右から数えてjビット目のビットを知りたい
```
(i >> j) & 1
```

# Union-Find Tree
実装が必要な関数は以下。

- unite(v1, v2)
- root(v)
- sameRoot(v)

亜種として各集合のサイズを返す関数が必要な時もある。

```
class UnionFind():
    def __init__(self, n):
        self.par = [-1 for _ in range(n)]
        self.sizeDict = { i: 1 for i in range(n)}

    def unite(self, v1, v2):
        '''
        connect v2 to v1.

        parent: v1
        child: v2
        '''
        r1 = self.root(v1)
        r2 = self.root(v2)
        if r1 == r2:
            return
        self.par[r2] = r1
        self.sizeDict[r1] += self.sizeDict[r2]

    def root(self, v):
        if self.par[v] == -1:
            return v
        self.par[v] = self.root(self.par[v])
        return self.par[v]

    def sameRoot(self, v1, v2):
        return self.root(v1) == self.root(v2)

    def size(self, v):
        return self.sizeDict[self.root(v)]
```

# BFS
用意する変数：que, visited
```
def bfs():
  que = deque()
  que.append((position, state))
  while que:
    position, state = q.popleft()
    check_goal(position)
    for next_point in movable(position):
      if not valid(next_point):
        continue
      que.append(next_point, next_state)
      visited(next_point)
```

- 最後の行でvisitする。(詳しくはわからない)
- dequeに突っ込むstateに情報を持たせるようにする。

# DFS
## iterative
用意する変数：stack, visited
```
def bfs():
  s = deque()
  s.append((position, state))
  while s:
    position, state = s.pop()
    check_goal(position)
    for next_point in movable(position):
      if not valid(next_point):
        continue
      s.append((next_point, next_state))
      visited(next_point)
```

## recursive
用意する変数：グローバルvisited
```
visited = [[...]]

def recursive_bfs(row, col):
  visited[row][col] = True
  
  for next_point in movable((row, col)):
    if not valid(next_point):
      continue
    if already_visited(next_point):
      continue
    recursive_bfs(*next_point)
  return

recursive_bfs(0, 0)
```

# Python Tips
```
def f():
  ans = 0
  def g():
    ans = 111
  return ans
f()
# output: 0
```
ネストされた関数から外側の関数の変数を変更したいときは、
nonlocal ans
'''
をつける。

# cpp標準入力

入力：行列(char)
```
H, W
a11, ..., a1W
...
aH1, ..., aHW
```
コード1
```
cin >> H >> W;
char** S = new char*[H];
rep(i, 0, H) S[i] = new char[W];
rep(j, 0, H) cin >> S[j]
```
コード2
```
char a[10000][10000];
cin >> H >> W;
rep(i, 0, H){
  rep(j, 0, W){
    cin >> S[i][j];
  }
}
```

# for文
DPの問題で、diagonalにfor文を回したい時がある。
参考: https://www.geeksforgeeks.org/zigzag-or-diagonal-traversal-of-matrix/
オフセットkを決めて、行または列のインデックスをloopすればよい。
```
for(int k=0; k<N; k++){
  for(int row=0; row<N; row++){
    int col = row + k;
    if(col<N) ...
  }
}
```

## できない理由
- ケースを考え忘れている

# 環境
テンプレ作成方法
https://stackoverflow.com/questions/55469524/how-to-write-vim-function-to-paste-a-template-text-into-current-file

# 参考
DP: http://home.wakatabe.com/ryo/wiki/index.php?%E3%82%A2%E3%83%AB%E3%82%B4%E3%83%AA%E3%82%BA%E3%83%A0#mb392f04

# Pypy or Python?
Pypyが遅いもの
- 文字列結合
- ソート

