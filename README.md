
# 区間スケジューリング
始点(終点)を昇順または降順ソート。
保持する値：始点の最大値, 終点の最小値


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
ナップザック (要素がN個、重さがWまでの制限を守った最大価値を求める。)

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


# 環境
テンプレ作成方法
https://stackoverflow.com/questions/55469524/how-to-write-vim-function-to-paste-a-template-text-into-current-file

# 参考
DP: http://home.wakatabe.com/ryo/wiki/index.php?%E3%82%A2%E3%83%AB%E3%82%B4%E3%83%AA%E3%82%BA%E3%83%A0#mb392f04
