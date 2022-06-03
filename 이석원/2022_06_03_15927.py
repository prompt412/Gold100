import sys
sys.setrecursionlimit(10**6)

getInt = lambda: int(sys.stdin.readline())
getStr = lambda: sys.stdin.readline().rstrip()
getInts = lambda: list(map(int, sys.stdin.readline().split()))

def isPalindrome(s):
  l, r = 0, len(s)-1
  diff = True
  while l <= r:
    if s[l] != s[r]:
      diff = False
      break
    l, r = l+1, r-1
  return diff

def main():
  s = getStr()
  cnt = [0 for _ in range(128)]
  for c in s:
    cnt[ord(c)] += 1
  if sum(x == len(s) for x in cnt) == 1:
    print(-1)
    return
  print(len(s)-1 if isPalindrome(s) else len(s))

if __name__ == '__main__':
  main()
