import sys

def main():
  N = int(sys.stdin.readline())
  arr = []
  for _ in range(N):
    _, s, t = map(int, sys.stdin.readline().split())
    arr.append([s, 1])
    arr.append([t, -1])
  arr.sort()

  ret = 0
  cur = 0
  for _, c in arr:
    cur += c;
    ret = max(ret, cur)
  print(ret)

if __name__ == '__main__':
  main()

