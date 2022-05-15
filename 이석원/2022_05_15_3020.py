import sys
IN = sys.stdin.readline

def main():
  N, H = map(int, IN().split())
  arr = [0] * H
  for i in range(N):
    h = int(IN())
    if i % 2 == 0:
      arr[h] -= 1
    else:
      arr[-h] += 1

  ret = [N // 2, 1]
  cur = ret[0]
  for i in range(1, H):
    cur += arr[i]
    if cur < ret[0]:
      ret = [cur, 1]
    elif cur == ret[0]:
      ret[1] += 1
  print(*ret)

if __name__ == '__main__':
  main()

