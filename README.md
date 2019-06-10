# テンプレ

### 区間スケジューリング
始点(終点)を昇順(降順)ソート。
保持する値：始点の最大値, 終点の最小値


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
