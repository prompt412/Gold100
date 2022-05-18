import sys

getInt = lambda: int(sys.stdin.readline())
getInts = lambda: list(map(int, sys.stdin.readline().split()))

def main():
  N = getInt()
  arr = getInts()

  INF = pow(2, 31)
  dp = [[0 for _ in range(N)] for _ in range(2)]
  dp[0][0] = arr[0]
  ret = arr[0]
  for i in range(1, N):
    dp[0][i] = max(arr[i], dp[0][i-1] + arr[i])
    dp[1][i] = max(dp[1][i-1] + arr[i], dp[0][i-2] + arr[i] if i >= 2 else -INF)
    ret = max(ret, dp[0][i], dp[1][i])
  print(ret)

if __name__ == '__main__':
  main()
