import sys
# sys.setrecursionlimit(10**6)

getInt = lambda: int(sys.stdin.readline())
getStr = lambda: sys.stdin.readline().rstrip()
getInts = lambda: list(map(int, sys.stdin.readline().split()))

N = getInt()
xs, ys = {}, {}
for _ in range(N):
  x, y = getInts()
  xs[x] = xs.get(x, [])
  xs[x].append(y)
  ys[y] = ys.get(y, [])
  ys[y].append(x)

for i in range(2):
  d = xs if i == 0 else ys
  line = 0
  ss = set()
  for x, yy in d.items():
    if len(yy) >= 2:
      line += 1
    else:
      ss.add(yy[0])
  if (line <= 3 and len(ss) == 0) or (line <= 2 and len(ss) == 1):
     print(1)
     exit(0)

print(0)
