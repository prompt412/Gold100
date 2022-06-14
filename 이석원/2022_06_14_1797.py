import sys
# sys.setrecursionlimit(10**6)

getInt = lambda: int(sys.stdin.readline())
getStr = lambda: sys.stdin.readline().rstrip()
getInts = lambda: list(map(int, sys.stdin.readline().split()))

N = getInt()
arr = sorted([getInts() for _ in range(N)], key=lambda x: x[1])
zeros, ones = [len(list(filter(lambda x: x[0] == i, arr))) for i in range(2)]
if zeros == ones:
  print(arr[-1][1] - arr[0][1])
  exit(0)

if zeros > ones:
  for i in range(N):
    arr[i][0] = 0 if arr[i][0] == 1 else 1

d, cur, ret = {}, 0, 0
for i in range(N):
  cur += 1 if arr[i][0] == 1 else -1
  ret = max(ret, arr[i][1] - d.get(cur, float('inf')))
  if i < N-1 and cur not in d:
    d[cur] = arr[i+1][1]
print(ret)
