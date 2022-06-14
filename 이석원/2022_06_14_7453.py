import sys
# sys.setrecursionlimit(10**6)

getInt = lambda: int(sys.stdin.readline())
getStr = lambda: sys.stdin.readline().rstrip()
getInts = lambda: list(map(int, sys.stdin.readline().split()))

N = getInt()
board = [getInts() for _ in range(N)]

d = {}
for i in range(N):
  for j in range(N):
    s = board[i][0] + board[j][1]
    d[s] = d.get(s, 0) + 1

ret = 0
for i in range(N):
  for j in range(N):
    s = board[i][2] + board[j][3]
    ret += d.get(-s, 0)
print(ret)
