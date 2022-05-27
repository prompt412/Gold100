import sys
# sys.setrecursionlimit(10**6)

getInt = lambda: int(sys.stdin.readline())
getStr = lambda: sys.stdin.readline().rstrip()
getInts = lambda: list(map(int, sys.stdin.readline().split()))

N = getInt()
sz = [0 for _ in range(N)]
edges = [getInts() for _ in range(N-1)]
for a, b in edges:
  a, b = a-1, b-1
  sz[a] += 1
  sz[b] += 1

D, G = 0, 0
for a, b in edges:
  a, b = a-1, b-1
  D += (sz[a] - 1) * (sz[b] - 1)
for cur in range(N):
  l = sz[cur]
  G += l * (l-1) * (l-2) / 6

if D > G*3:
  print('D')
elif D < G*3:
  print('G')
else:
  print('DUDUDUNGA')

