import sys

def main():
  N = int(sys.stdin.readline())
  c = list(map(int, sys.stdin.readline().split())); c.sort()
  cpos = [0] * N;
  M = int(sys.stdin.readline())
  b = list(map(int, sys.stdin.readline().split())); b.sort()

  for i in range(N):
    while cpos[i] < M and c[i] >= b[cpos[i]]:
      cpos[i] += 1
    cpos[i] -= 1

  if cpos[-1] < M-1:
    print(-1)
    return

  for t in range(1, 1000000):
    for i in range(N):
      while cpos[i] >= 0 and b[cpos[i]] == -1:
        cpos[i] -= 1
      if cpos[i] < 0:
        continue

      b[cpos[i]] = -1
      while cpos[i] >= 0 and b[cpos[i]] == -1:
        cpos[i] -= 1

    if cpos[-1] == -1:
      print(t)
      return

  assert False

if __name__ == '__main__':
  main()
