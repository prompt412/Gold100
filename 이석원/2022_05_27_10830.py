import sys
sys.setrecursionlimit(10**6)

getInt = lambda: int(sys.stdin.readline())
getStr = lambda: sys.stdin.readline().rstrip()
getInts = lambda: list(map(int, sys.stdin.readline().split()))

N, M = getInts()
matx = [getInts() for _ in range(N)]
cur = [[1 if i == j else 0 for j in range(N)] for i in range(N)]

def mul(a, b):
  N = len(a)
  c = [[0 for _ in range(N)] for _ in range(N)]
  for i in range(N):
    for j in range(N):
      for k in range(N):
        c[i][j] += a[i][k] * b[k][j]
        c[i][j] %= 1000
  return c

for b in bin(M)[2:]:
  cur = mul(cur, cur)
  if b == '1':
    cur = mul(cur, matx)

for row in cur:
  print(*row)

