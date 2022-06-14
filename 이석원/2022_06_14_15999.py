import sys
import re
# sys.setrecursionlimit(10**6)

getInt = lambda: int(sys.stdin.readline())
getStr = lambda: sys.stdin.readline().rstrip()
getInts = lambda: list(map(int, sys.stdin.readline().split()))

d = [[0, -1], [0, 1], [1, 0], [-1, 0]]

N, M = getInts()
board = [getStr() for _ in range(N)]

cnt = N*M
for i in range(N):
  for j in range(M):
    for xd, yd in d:
      ni, nj = i + xd, j + yd
      if 0 <= ni < N and 0 <= nj < M and board[ni][nj] != board[i][j]:
        cnt -= 1
        break

ret, cur, mod = 1, 2, 1000000007
while cnt > 0:
  if cnt & 1:
    ret = (ret * cur) % mod
  cur = (cur * cur) % mod
  cnt >>= 1
print(ret)

