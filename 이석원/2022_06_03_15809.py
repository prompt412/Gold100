import sys
sys.setrecursionlimit(10**6)

getInt = lambda: int(sys.stdin.readline())
getStr = lambda: sys.stdin.readline().rstrip()
getInts = lambda: list(map(int, sys.stdin.readline().split()))

class UnionFind:
  def __init__(self, N, sz):
    self._arr = [-1 for _ in range(N)]
    self._sz = sz

  def root(self, i):
    if self._arr[i] < 0:
      return i
    else:
      self._arr[i] = self.root(self._arr[i])
      return self._arr[i]

  def size(self, i):
    return -self._arr[self.root(i)]

  def merge(self, a, b):
    ra, rb = self.root(a), self.root(b)
    if ra == rb:
      return
    if self.size(ra) < self.size(rb):
      ra, rb = rb, ra   # now self.size(ra) >= self.size(rb).
    self._arr[ra] += self._arr[rb]
    self._arr[rb] = ra

    self._sz[ra] += self._sz[rb]
    self._sz[rb] = 0

  def fight(self, a, b):
    ra, rb = self.root(a), self.root(b)
    if ra == rb:
      return
    if self._sz[ra] < self._sz[rb]:
      ra, rb = rb, ra   # now self.size(ra) >= self.size(rb).
    self._arr[ra] += self._arr[rb]
    self._arr[rb] = ra

    self._sz[ra] -= self._sz[rb]
    self._sz[rb] = 0

def main():
  N, M = getInts()
  sz = [getInt() for _ in range(N)]
  uf = UnionFind(N, sz)
  for _ in range(M):
    op, a, b = getInts()
    a, b = a-1, b-1
    if op == 1:
      uf.merge(a, b)
    else:
      assert op == 2
      uf.fight(a, b)
  sz = list(filter(lambda x: x > 0, uf._sz))
  sz.sort()
  print(len(sz))
  print(' '.join([str(x) for x in sz]))

if __name__ == '__main__':
  main()
