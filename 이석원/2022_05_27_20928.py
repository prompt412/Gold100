import sys
# sys.setrecursionlimit(10**6)

getInt = lambda: int(sys.stdin.readline())
getStr = lambda: sys.stdin.readline().rstrip()
getInts = lambda: list(map(int, sys.stdin.readline().split()))

N, M = getInts()
pos = getInts()
dist = getInts()

end = [-1 for _ in range(N)]
end[0] = pos[0] + dist[0]
cur = 1

for i in range(N):
  if M <= end[i]:
    print(i)
    exit(0)
  elif i == N-1:
    print(-1)
    exit(0)
  while cur < N and pos[cur] <= end[i]:
    end[i+1] = max(end[i+1], pos[cur] + dist[cur])
    cur += 1
print(-1)

