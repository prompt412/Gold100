import sys
from collections import deque
# sys.setrecursionlimit(10**6)

getInt = lambda: int(sys.stdin.readline())
getStr = lambda: sys.stdin.readline().rstrip()
getInts = lambda: list(map(int, sys.stdin.readline().split()))

N = getInt()
arr = sorted(getInts())
pos, neg = [], []
for e in arr:
  (pos if e >= 0 else neg).append(e)
pos.reverse()

pdq, ndq = deque(), deque()
for _ in range(2):
  dq = (pdq if _%2 == 0 else ndq)
  a = (pos if _%2 == 0 else neg)
  for i in range(len(a)):
    if i%2 == 0:
      dq.appendleft(a[i])
    else:
      dq.append(a[i])
if len(pdq) % 2 == 0:
  pdq.reverse()
if len(ndq) % 2 == 1:
  ndq.reverse()

print(*ndq, *pdq)
