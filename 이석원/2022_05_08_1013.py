import sys

def solve(s):
  # (100+1+ | 01)+
  i = 0
  #print(len(s))
  while i < len(s):
    #print(f'i={i}, s[i:i+2]={s[i:i+2]}')
    if s[i:i+2] == '01':
      i += 2

    elif s[i:i+2] == '10':
      i += 2

      i0 = i
      while i < len(s) and s[i] == '0':
        i += 1
      zerocnt = i - i0
      if zerocnt == 0:
        return False

      i1 = i
      while i < len(s) and s[i] == '1':
        i += 1
      onecnt = i - i1
      if onecnt == 0:
        return False

      if i < len(s) and s[i:i+2] != '01' and onecnt >= 2:
        i -= 1

    else:
      return False

  return True

def main():
  T = int(sys.stdin.readline())
  for i in range(T):
    s = sys.stdin.readline()[:-1]
    if solve(s):
      print('YES')
    else:
      print('NO')

main()

