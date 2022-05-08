#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <tuple>
#include <vector>
#include <stack>
#include <queue>
#include <deque>
#include <climits>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>
#include <string>
#include <sstream>
#include <iostream>
#include <regex>

using namespace std;
using ii = pair<int, int>;
using iii = tuple<int, int, int>;

#define X first
#define Y second

int n, m, k;
int ret = -1;
string lamps[100];

int main() {

	cin >> n >> m;
	for (int i = 0; i < n; i++) cin >> lamps[i];
    
    cin >> k;
	for (int i = 0; i < n; i++) {
		int cnt = 0, mx = 0;

		for (int j = 0; j < m; j++) {
			if (lamps[i][j] == '0') cnt++;
		}
		if (cnt <= k && (cnt+k)%2 == 0) {
			for (int j = 0; j < n; j++)
				mx += (int)(!lamps[i].compare(lamps[j]));
        }
		ret = max(ret, mx);
	}
	cout << ret;
    return 0;
}