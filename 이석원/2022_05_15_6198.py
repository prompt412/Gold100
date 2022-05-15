import sys

getInt = lambda: int(sys.stdin.readline())
getInts = lambda: list(map(int, sys.stdin.readline().split()))

def main():
  N = getInt()
  arr = [getInt() for _ in range(N)]

  ret = 0
  stack = []
  for h in reversed(arr):
    c = 1
    while len(stack) > 0 and h > stack[-1][0]:
      _, cnt = stack.pop()
      ret += cnt
      c += cnt
    stack.append([h, c])
    # print(stack)
  print(ret)

if __name__ == '__main__':
  main()
