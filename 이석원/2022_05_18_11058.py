import sys

getInt = lambda: int(sys.stdin.readline())
getInts = lambda: list(map(int, sys.stdin.readline().split()))

def main():
  N = getInt()
  dp = [i for i in range(N+1)]
  for i in range(1, N+1):
    for j in range(i+3, N+1):
      dp[j] = max(dp[j], dp[i] * (j-i-1))
  print(dp[-1])

if __name__ == '__main__':
  main()
