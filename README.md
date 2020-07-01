#Atcoder
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

## 繰り返し二乗法
TL;DR: 指数nを二進数に変換し、立っているビットがあったらxをresに積み重ねていく。xはつねにビットの位置に対応したべき乗になっているようにする。

```python
def pow(x, n):
  ans = 1
  while(n > 0):
    if(bin(n & 1) == bin(1)):
      ans = ans*x
    x = x*x
    n = n >> 1
  return ans
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

## 整数
- 何回割れるのかに注目する
- N個の数の公倍数系は二つの数で実験してみる
- gcd(a, b) = gとして、a = ga', b = gb'と分解してみる (ペズーの等式)

## nCm mod p
参考：http://drken1215.hatenablog.com/entry/2018/06/08/210000

原理：
- a*b*c mod p = (a*b mod p) * c mod p (足し算引き算掛け算は一つずつ重ねて良い)
- 割り算ではこれが成り立たないので逆元を考える必要がある。フェルマーの小定理より逆元はa^(p-2)である。
- nCk mod p = n! * (k!)^(-1) * ((n-k)!)^(-1) mod p という感じで、三つの掛け算に分解できる。逆元さえ求められればよい。
```
fac[i]: i!
inv[i]: iの逆元
finv[i]: i!の逆元
```

```python
# 10 ** 7 might cause MLE
fac = [-1] * (10**6+1)
inv = [-1] * (10**6+1)
finv = [-1] * (10**6+1)

fac[0] = fac[1] = 1
inv[1] = 1
finv[0] = finv[1] = 1

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

## 逆元
x * x^(p-2) = 1 (mod p)を用いると、(pは素数)
```python
a_gyakugen = mod_pow(a, mod-2)
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

# 尺取り法
終端をfor文で回すと良いかも(使ったサンプル数1)
```
for en in range(N):
  do_something()
  if not satisfy:
     do_something(st)
   else:
     ans += 1
```

# 累積和

### 1次元

```
配列の[left, right)に関する和: s[right] - s[left]
```

```python
a = [1,2,3]
s = [0, 1, 3, 6]
for i in range(len(a)):
  s[i+1] = s[i] + a[i]
```

### 2次元
```
G = [0...C) × [0...R)
s2d = [[0 for _ in range(R+1)] for __ in range(C+1)]
for r in range(R):
  for c in range(C):
    s2d[r+1][c+1] = s2d[r][c+1] + s2d[r+1][c] - s2d[r][c] + G[r][c]

def query_cs2d(s, x1, x2, y1, y2):
  # [x1, x2) × [y1, y2)
  if x2 < x1:
    x1, x2 = x2, x1
  if y2 < y1:
    y1, y2 = y2, y1
  return s[x2][y2] - s[x1][y2] - s[x2][y1] + s[x1][y1]  
```

# bit全探索

## bit操作
### n桁(0ビットからn-1ビットまで)を探索したい
```
for i in (1 << n):
  pass
```

### iという数字に対し、右から数えてjビット目のビットを知りたい
```
(i >> j) & 1
```

### 2進数での桁数を知りたい
```python
def digit_bin(n):
    cnt = 1
    while n > 1:
        n = n >> 1
        cnt += 1
    return cnt
```


### 1の桁数を数える
```python
def count_one(n):
    cnt = 0
    i = 0
    while n:
        if n & 1 == 1:
            cnt += 1
        i += 1
        n = n >> 1
    return cnt
```

# Priority-Queue
Min-heap用の関数である。
- heapq.heapify(list) # returns None
- heaqp.heappush(b)
- heapq.heappop()

Max-heapの時は、
- heapq.heapify([-x for x in list]) # returns None
- heapq.heappush(-b)
- -heapq.heappop()

とする。

## Segment Tree
https://www.creativ.xyz/segment-tree-entrance-999/
がわかりやすい

```python
class SegmentTree():
    def __init__(self, arr):
        self.arr = arr
        self.size = self.calc_size(arr)
        self.n = (self.size+ 1) // 2 
        self.value = [2**31 - 1 for _ in range(self.size)] # ==== change accordingly ====

    def calc_size(self, array):
        i = 1
        while i < len(array):
            i = i << 1
        return (i << 1) - 1

    def update(self, i, x):
        # 1 + 2 + ... + N/2 = N-1
        i += self.n - 1
        self.value[i] = x
        while i > 0:
            i = (i - 1)//2
            self.value[i] = min(self.value[2*i+1], self.value[2*i+2]) # ==== change accordingly ====

    def query(self, l, r):
        # find [l, r)
        def _query(l, r, node_i, node_l, node_r):
            # node_i: node = value[node_i]
            # node_l: node.leftChild is in charge of [node_l, m)
            # node_r: node.rightChild is in charge of [m, node_r)

            if node_r <= l or r <= node_l:
                return inf # ==== change accordingly ====

            if l <= node_l and node_r <= r:
                return self.value[node_i]

            c1 = _query(l, r, 2 * node_i + 1, node_l, (node_l + node_r) // 2)
            c2 = _query(l, r, 2 * node_i + 2, (node_l + node_r) // 2, node_r)
            return min(c1, c2) # ==== change accordingly

        return _query(l, r+1, 0, 0, self.n)
```

# FenwickTree (BIT)
Segment Treeより定数倍高速
```python
class BIT():
    def __init__(self, n):
        self.n = self.calc_size(n) + 1
        self.value = [0] * (self.n)

    def calc_size(self, n):
        i = 1
        while i < n:
            i = i << 1
        return i

    def add(self, i, x):
        # 1-indexed
        while i < self.n:
            self.value[i] += x
            i += self.lsb(i)

    def cumsum(self, i):
        # 1-indexed
        # [1, i+1)
        cnt = 0
        while i > 0:
            cnt += self.value[i]
            i -= self.lsb(i)
        return cnt

    def lsb(self, i):
        return i & -i

    def __str__(self):
        string = '''BIT.n: {}, BIT.value: {}
        '''.format(self.n, self.value)
        return string
```
長さ8のArrayに対して、
[x, 0, 0, 0, 0, 0, 0, 0, 0]
を考える。
1, 3, 5, 7の葉と、それらの一つ上は使っていく。2, 4, 6, 8は冗長なので使わない。
操作したいArrayのindexに対して、ツリー上の該当する累積和ブロックが勝手に対応するようになる。(binaryの性質)


# Union-Find Tree
実装が必要な関数は以下。

- unite(v1, v2)
- root(v)
- sameRoot(v)

https://note.nkmk.me/python-union-find/
より引用。

parentsには-要素数が入る。

```python
class UnionFind():
    def __init__(self, n):
        self.n = n
        self.parents = [-1] * n

    def find(self, x):
        if self.parents[x] < 0:
            return x
        else:
            self.parents[x] = self.find(self.parents[x])
            return self.parents[x]

    def union(self, x, y):
        x = self.find(x)
        y = self.find(y)

        if x == y:
            return

        if self.parents[x] > self.parents[y]:
            x, y = y, x

        self.parents[x] += self.parents[y]
        self.parents[y] = x

    def size(self, x):
        return -self.parents[self.find(x)]

    def same(self, x, y):
        return self.find(x) == self.find(y)

    def members(self, x):
        root = self.find(x)
        return [i for i in range(self.n) if self.find(i) == root]

    def roots(self):
        return [i for i, x in enumerate(self.parents) if x < 0]

    def group_count(self):
        return len(self.roots())

    def all_group_members(self):
        return {r: self.members(r) for r in self.roots()}

    def __str__(self):
        return '\n'.join('{}: {}'.format(r, self.members(r)) for r in self.roots())
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

# 木
閉路はない。

## Prim法

## Kruscal法
1. エッジをコスト順にソートする。
2. 閉路ができなければ辺を仲間にいれる。 
+ 閉路の判定にはunionfindを使う。
計算量はElog(E)で、特にE=V^2が最悪。そのときでもElog(V)がなりたつ。
```python
sort(edges)
uf = UnionFind()
cnt = 0
for i in range(len(edges)):
  e = edges[i]
  if not uf.same(e.fr, e.to):
    uf.union(e.fr, e.to)
    cnt += e.cost
```

# グラフ

## Dijkstra
負辺なしかつ閉路なしで使える

```python
unvisited = set(V)
d[start_v] = 0
while unvisited:
  next_v = find_min_v_from_unvisited(d)
  unvisited.pop(next_v)
  relax(start_v, next_v, d) # 最短距離を更新する
```

## Bellman-Ford
負の閉路あっても使える

```python
for _ in range(V-1):
  for edge in edges:
    fr, to, cost = edge
    relax(fr, to, cost)
```

O(VlogV + ElogV)の書き方
```python
def dijkstra(st):
  d = [inf] * N
  d[st] = 0
  q = []
  init_cost = 0
  heapq.heappush(q, (init_cost, st))
  while q:
    cost, u = heapq.heappop(q)
    for v_cost, v in G[u]:
      if cost + v_cost < d[v]:
        d[v] = cost + v_cost
        heapq.heappush(q, (d[v], v))
  return d
```

ノードに関するiteration1回につき、最低1つはノードへの最短距離が確定する。
出発点以外のノードはV-1個あるので、V-1回ループすればよい。

## Warshall–Floyd
全頂点間の最短距離がわかる。
O(V^3)なので V <= 200ぐらいで使える。
```python
# Gの距離情報をdに移しておく
# kijの添字を間違うと死
for k in range(V):
  for i in range(V):
    for j in range(V):
      d[i][j] = min(d[i][j], d[i][k] + d[k][j])
```

## トポロジカルソートの数え上げ
- https://atcoder.jp/contests/abc041/tasks/abc041_d

```python
```

## BFS
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

## DFS
### iterative
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

### recursive
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

# 数学系

## 互除法
```python
def gcd(a, b):
  if b == 0:
    return a
  return gcd(b, a % b)
```

## 拡張ユークリッド

再帰の挙動が理解できない。
https://qiita.com/drken/items/b97ff231e43bce50199a


## 苦手なもの
- 正しいインデックスの操作。(累積和とか)
  - 開区間で考える。s[r] - s[0] = sum[0, r)など。

## 二分探索を使う系の問題
- 「最小値を求めよ」系の問題は「X以下なら可能か？」という判定問題になるかも


## できない理由
- ケースを考え忘れている
- 二次元配列を一次元配列にできないか考えてみる

## よくあるミス
- 0 <= r < W を 0 <= r < Cと書き間違える


# 環境
テンプレ作成方法
https://stackoverflow.com/questions/55469524/how-to-write-vim-function-to-paste-a-template-text-into-current-file

# 参考
DP: http://home.wakatabe.com/ryo/wiki/index.php?%E3%82%A2%E3%83%AB%E3%82%B4%E3%83%AA%E3%82%BA%E3%83%A0#mb392f04

# Pypy or Python?
Pypyが遅いもの
- 文字列結合
- ソート

