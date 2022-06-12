import sys
sys.setrecursionlimit(10**6)

getInt = lambda: int(sys.stdin.readline())
getStr = lambda: sys.stdin.readline().rstrip()
getInts = lambda: list(map(int, sys.stdin.readline().split()))

def DFS(graph, cur, visited, left, right, isl):
  (left if isl else right)[cur] = True

  for e in graph[cur]:
    (right if isl else left)[e] = True
    if not visited[e]:
      visited[e] = True
      DFS(graph, e, visited, left, right, not isl)

def solve():
  V, E = getInts()
  graph = [[] for _ in range(V)]
  for _ in range(E):
    a, b = getInts()
    a, b = a-1, b-1
    graph[a].append(b)
    graph[b].append(a)

  visited = [False for _ in range(V)]
  left = [False for _ in range(V)]
  right = [False for _ in range(V)]
  for i in range(V):
    if not visited[i]:
      visited[i] = True
      left[i] = True
      DFS(graph, i, visited, left, right, True)

  for i in range(V):
    if left[i] and right[i]:
      print('NO')
      return
  print('YES')

def main():
  for _ in range(getInt()):
    solve()

if __name__ == '__main__':
  main()
