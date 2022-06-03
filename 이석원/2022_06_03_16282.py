import sys
sys.setrecursionlimit(10**6)

getInt = lambda: int(sys.stdin.readline())
getStr = lambda: sys.stdin.readline().rstrip()
getInts = lambda: list(map(int, sys.stdin.readline().split()))

def main():
  f = lambda x: x + (x+1) * (2**(x+1) - 1)
  N = getInt()
  l, r, ret = 1, 55, -1
  while l <= r:
    m = (l + r) // 2
    if N <= f(m):
      r = m - 1
      ret = m
    else:
      l = m + 1
  print(ret)

if __name__ == '__main__':
  main()
