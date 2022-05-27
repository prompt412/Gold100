import sys
sys.setrecursionlimit(10**6)

getInt = lambda: int(sys.stdin.readline())
getStr = lambda: sys.stdin.readline().rstrip()
getInts = lambda: list(map(int, sys.stdin.readline().split()))

def DFS(graph, cur, depth):
  if depth[cur] != 0:
    return depth[cur]

  for e in graph[cur]:
    depth[cur] = max(depth[cur], DFS(graph, e, depth))
  depth[cur] += 1
  return depth[cur]

def main():
  N, M = getInts()
  h = getInts()
  graph = [[] for _ in range(N)]
  for i in range(1, M+1):
    a, b = getInts()
    a -= 1
    b -= 1
    if h[a] < h[b]:
      graph[a].append(b)
    elif h[a] > h[b]:
      graph[b].append(a)
  depth = [0 for _ in range(N)]
  print('\n'.join([str(DFS(graph, i, depth)) for i in range(N)]))

if __name__ == '__main__':
  main()
