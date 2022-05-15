import datetime as dt
import re
import requests
import sys

USER = 'prompt412'
REPO = 'Gold100'
BRANCH = 'main'
URL = f'https://api.github.com/repos/{USER}/{REPO}/git/trees/{BRANCH}?recursive=1'

FILENAME = re.compile('^[가-힣]+/202[0-9]_(0[1-9]|1[012])_(0[1-9]|[12][0-9]|3[01])_.+')


def main():
  base_day = dt.datetime.strptime(sys.argv[1], '%Y_%m_%d')
  start_date = (base_day - dt.timedelta(days=6)).strftime("%Y_%m_%d")
  end_date = base_day.strftime("%Y_%m_%d")
  print(f'{start_date} 부터 {end_date} 까지의 풀이를 셉니다.')

  repo = requests.get(URL).json()
  counter = {}

  for file in repo['tree']:
    if not FILENAME.match(file['path']):
      continue

    s = file['path'].split('/')
    name, file_date = s[0], s[1][:10]

    counter[name] = counter.get(name, 0)
    if start_date <= file_date <= end_date:
      counter[name] += 1

  for name, count in counter.items():
    print(f'- {name}({count})')


if __name__ == '__main__':
  if len(sys.argv) == 2:
    main()
  else:
    print(f'사용법:\n  $ python3 {sys.argv[0]} <기준일 (ex.2022_05_15)>')
