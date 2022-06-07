import sys
# sys.setrecursionlimit(10**6)

getInt = lambda: int(sys.stdin.readline())
getStr = lambda: sys.stdin.readline().rstrip()
getInts = lambda: list(map(int, sys.stdin.readline().split()))

def main():
  N = getInt()
  arr = getInts(); arr.sort()
  ret = [1e9+7] * 3
  retsum = sum(ret)
  for i in range(N):
    arri = arr[i]
    j, k = i+1, N-1
    while j < k:
      cur = arri + arr[j] + arr[k]
      if abs(cur) < abs(retsum):
        ret = [arri, arr[j], arr[k]]
        retsum = cur
      if cur > 0:
        k -= 1
      elif cur < 0:
        j += 1
      else:
        print(*ret)
        return
  print(*ret)

if __name__ == '__main__':
  main()
