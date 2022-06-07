import sys
sys.setrecursionlimit(10**6)

getInt = lambda: int(sys.stdin.readline())
getStr = lambda: sys.stdin.readline().rstrip()
getInts = lambda: list(map(int, sys.stdin.readline().split()))

class UnionFind:
  def __init__(self, N):
    self._arr = [-1 for _ in range(N)]

  def root(self, i):
    if self._arr[i] < 0:
      return i
    self._arr[i] = self.root(self._arr[i])
    return self._arr[i]

  def size(self, i):
    return -self._arr[self.root(i)]

  def merge(self, a, b):
    ra, rb = self.root(a), self.root(b)
    if ra == rb:
      return False
    if self.size(ra) < self.size(rb):
      ra, rb = rb, ra   # now self.size(ra) >= self.size(rb).
    self._arr[ra] += self._arr[rb]
    self._arr[rb] = ra
    return True

def main():
  N, M = getInts()
  edges = sorted([getInts() for _ in range(M)], key=lambda x: -x[2])
  src, sink = getInts()

  uf = UnionFind(N+1)
  for a, b, c in edges:
    uf.merge(a, b)
    if uf.root(src) == uf.root(sink):
      print(c)
      break

if __name__ == '__main__':
  main()
