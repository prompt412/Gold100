import sys
# sys.setrecursionlimit(10**6)

getInt = lambda: int(sys.stdin.readline())
getStr = lambda: sys.stdin.readline().rstrip()
getInts = lambda: list(map(int, sys.stdin.readline().split()))

L, R, K = [getInt() for _ in range(3)]
ret = 0
if K == 2:
  ret = max(0, R - max(L, 3) + 1)
elif K == 3:
  l = max(6, (L + 2) // 3 * 3)
  r = R // 3 * 3
  ret = max(0, (r - l) // 3 + 1)
elif K == 4:
  l = max(10, (L + 1) // 2 * 2)
  r = R // 2 * 2
  ret = max(0, (r - l) // 2 + 1)
  if l <= 12 <= r:
    ret -= 1
elif K == 5:
  l = max(15, (L + 4) // 5 * 5)
  r = R // 5 * 5
  ret = max(0, (r - l) // 5 + 1)
print(ret)
