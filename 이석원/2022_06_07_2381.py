import sys
sys.setrecursionlimit(10**6)

getInt = lambda: int(sys.stdin.readline())
getStr = lambda: sys.stdin.readline().rstrip()
getInts = lambda: list(map(int, sys.stdin.readline().split()))

def main():
  N = getInt()
  ps = [getInts() for _ in range(N)]
  k1 = lambda x: x[0] + x[1]
  k2 = lambda x: x[0] - x[1]
  dist = lambda x, y: abs(x[0] - y[0]) + abs(x[1] - y[1])
  print(max(dist(min(ps, key=k1), max(ps, key=k1)),
            dist(min(ps, key=k2), max(ps, key=k2))))

if __name__ == '__main__':
  main()
