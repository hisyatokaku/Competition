# テンプレ

### 区間スケジューリング
始点(終点)を昇順または降順ソート。
保持する値：始点の最大値, 終点の最小値


### 文字列探索
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



### bit全探索
n桁(0ビットからn-1ビットまで)を探索したい
```
for i in (1 << n):
  pass
```

iという数字に対し、右から数えてjビット目のビットを知りたい
```
(i >> j) & 1
```

### BFS
用意する変数：queue, visited
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


# 環境

テンプレ作成方法
https://stackoverflow.com/questions/55469524/how-to-write-vim-function-to-paste-a-template-text-into-current-file
