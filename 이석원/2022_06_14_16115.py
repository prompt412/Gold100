import sys
import re
import math
# sys.setrecursionlimit(10**6)

getInt = lambda: int(sys.stdin.readline())
getStr = lambda: sys.stdin.readline().rstrip()
getInts = lambda: list(map(int, sys.stdin.readline().split()))

N = getInt()
d = {}
maxs = 0

for i in range(N):
  x, y = getInts()
  s = x**2 + y**2
  maxs = max(maxs, s)
  d[s] = d.get(s, [])
  d[s].append(math.atan2(y, x))

ret = 0
v = d[maxs]
v.sort()
v.append(v[0] + math.pi * 2)
for i in range(len(v) - 1):
  ret = max(ret, v[i+1] - v[i])

print(ret * 180 / math.pi)
