import sys

def main():
  N, M = map(int, sys.stdin.readline().split())
  row = [sys.stdin.readline().rstrip() for _ in range(N)]
  K = int(sys.stdin.readline())

  cnt = {}
  for r in row:
    cnt[r] = cnt.get(r, 0) + 1

  ret = 0
  for r, c in cnt.items():
    d = r.count('0')
    if K >= d and (K - d) % 2 == 0:
      ret = max(ret, int(c))
  print(ret)

if __name__ == '__main__':
  main()
