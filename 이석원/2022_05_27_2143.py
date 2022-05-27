import sys
# sys.setrecursionlimit(10**6)

getInt = lambda: int(sys.stdin.readline())
getStr = lambda: sys.stdin.readline().rstrip()
getInts = lambda: list(map(int, sys.stdin.readline().split()))

T = getInt()
N, arr1 = getInt(), [0] + getInts()
M, arr2 = getInt(), [0] + getInts()

for i in range(1, N+1):
  arr1[i] += arr1[i-1]
for i in range(1, M+1):
  arr2[i] += arr2[i-1]

d = {}
for i in range(N):
  for j in range(i+1, N+1):
    s = arr1[j] - arr1[i]
    d[s] = d.get(s, 0) + 1

ret = 0
for i in range(M):
  for j in range(i+1, M+1):
    s = arr2[j] - arr2[i]
    ret += d.get(T-s, 0)
print(ret)

