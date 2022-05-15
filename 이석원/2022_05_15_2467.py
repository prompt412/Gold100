import sys

def main():
  N = int(sys.stdin.readline())
  arr = list(map(int, sys.stdin.readline().split()))

  l = 0
  r = len(arr) - 1
  ret = None
  while l < r:
    if ret == None or abs(arr[r] + arr[l]) < abs(ret[1] + ret[0]):
      ret = [arr[l], arr[r]]
    if abs(arr[l]) > abs(arr[r]):
      l += 1
    else:
      r -= 1
  print(*ret)

if __name__ == '__main__':
  main()
