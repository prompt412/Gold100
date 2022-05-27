import sys

getInt = lambda: int(sys.stdin.readline())
getStr = lambda: sys.stdin.readline().rstrip()
getInts = lambda: list(map(int, sys.stdin.readline().split()))

def main():
  N = getStr()
  K = getInt() - 1

  c = N.count('1') + N.count('6') + N.count('2') + N.count('7')
  if pow(2, c) < K+1:
    print(-1)
    return

  arr = list(N)
  bb = bin(K)[2:].zfill(c)
  j = 0
  for i in range(len(N)):
    if not arr[i] in '1267':
      continue
    b = bb[j]
    if b == '0':
      if arr[i] == '1' or arr[i] == '6':
        arr[i] = '1'
      elif arr[i] == '2' or arr[i] == '7':
        arr[i] = '2'
      j += 1
    else:
      if arr[i] == '1' or arr[i] == '6':
        arr[i] = '6'
      elif arr[i] == '2' or arr[i] == '7':
        arr[i] = '7'
      j += 1
  print(''.join(arr))

if __name__ == '__main__':
  main()
