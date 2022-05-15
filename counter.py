import datetime as dt
import re
import requests
import sys

USER = 'prompt412'
REPO = 'Gold100'
BRANCH = 'main'
TREE_URL = f'https://api.github.com/repos/{USER}/{REPO}/git/trees/{BRANCH}?recursive=1'


def get_target_count(readme):
  counter = {}

  for i in range(len(readme)):
    if readme[i] != '## 진행 인원':
      continue
    i += 1
    number = re.compile('\d+')
    while i < len(readme) and readme[i] != '## 진행 방식':
      name = readme[i].split()[1]
      nums = number.findall(readme[i + 1])
      counter[name] = int(nums[0]) if len(nums) >= 1 else 0
      i += 2
    break

  return counter


def get_solved_count(repo_tree, start_date, end_date):
  counter = {}

  filename = re.compile('^[가-힣]+/202[0-9]_(0[1-9]|1[012])_(0[1-9]|[12][0-9]|3[01])_.+')
  for file in repo_tree:
    if not filename.match(file['path']):
      continue

    s = file['path'].split('/')
    name, file_date = s[0], s[1][:10]

    if start_date <= file_date <= end_date:
      counter[name] = counter.get(name, 0) + 1

  return counter


def write_to_readme(readme_path, readme, solved_lines, start_day, end_day):
  def get_order_of_day(day, weekday):   # monday=0, sunday=6
    day += (5 - weekday)  # set to Saturday
    return (day + 6) // 7

  start_month, start_week = start_day.month, get_order_of_day(start_day.day, start_day.weekday())
  end_day = end_day - dt.timedelta(days=1)
  end_month, end_week = end_day.month, get_order_of_day(end_day.day, end_day.weekday())

  # Check the order of the weeks where start day (Monday) and end day - 1 (Saturday) are placed.
  week = f'#### {start_month}월 {start_week}주'
  if start_month != end_month:
    week += f' / {end_month}월 {end_week}주'

  split_idx = readme.index('## 진행 상황') + 1
  new_readme = readme[:split_idx] + [week] + solved_lines + readme[split_idx:]
  new_readme = '\n'.join(new_readme)

  with open(readme_path, 'w') as f:
    f.write(new_readme)


def main():
  readme_path, base_date = sys.argv[1], sys.argv[2]

  with open(readme_path, 'r') as f:
    readme = list(filter(lambda x: len(x) > 0, f.read().split('\n')))
  assert len(readme) >= 10

  target_count = get_target_count(readme)

  repo_tree = requests.get(TREE_URL).json()['tree']
  end_day = dt.datetime.strptime(sys.argv[2], '%Y_%m_%d')
  end_date = end_day.strftime("%Y_%m_%d")
  start_day = end_day - dt.timedelta(days=6)
  start_date = start_day.strftime("%Y_%m_%d")
  assert end_day.weekday() == 6, "Base day should be Sunday"

  solved_count = get_solved_count(repo_tree, start_date, end_date)

  solved_lines = []
  for name, target in target_count.items():
    solved = solved_count.get(name, 0)
    solved_lines.append(f'- {name}({solved}){" 🏅" if solved >= target else ""}')

  write_to_readme(readme_path, readme, solved_lines, start_day, end_day)


if __name__ == '__main__':
  if len(sys.argv) == 3:
    main()
  else:
    print(f'Usage: python3 {sys.argv[0]} <target readme path> <base date (ex.2022_05_15)>')
