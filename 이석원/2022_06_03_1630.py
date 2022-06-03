import sys
sys.setrecursionlimit(10**6)

getInt = lambda: int(sys.stdin.readline())
getStr = lambda: sys.stdin.readline().rstrip()
getInts = lambda: list(map(int, sys.stdin.readline().split()))

def main():
  N = getInt()
  p = [True for _ in range(N+1)]
  ret = 1
  for i in range(2, N+1):
    if not p[i]:
      continue
    for j in range(i*2, N+1, i):
      p[j] = False
    a = 1
    while a*i <= N:
      a *= i
      ret = (ret * i) % 987654321
  print(ret)

if __name__ == '__main__':
  main()
