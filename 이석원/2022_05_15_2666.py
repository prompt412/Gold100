import sys

def dp(apos, bpos, order, accum):
  if 'ret' not in dp.__dict__:
    dp.ret = 10000
  if dp.ret < accum:
    return
  if len(order) == 0:
    dp.ret = min(dp.ret, accum)
    return
  dp(apos, order[0], order[1:], accum + abs(bpos - order[0]))
  dp(order[0], bpos, order[1:], accum + abs(apos - order[0]))

def main():
  N = int(sys.stdin.readline())
  a, b = map(int, sys.stdin.readline().split())
  M = int(sys.stdin.readline())
  order = [int(sys.stdin.readline()) for _ in range(M)]
  dp(a, b, order, 0)
  print(dp.ret)

if __name__ == '__main__':
  main()

