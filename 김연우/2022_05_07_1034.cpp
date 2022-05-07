#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <vector>
#include <queue>
#include <algorithm>
#include <iostream>
#include <sstream>
#include <string>
#include <bitset>
#include <map>
#include <set>
#include <tuple>
#include <string.h>
#include <math.h>
#include <random>
#include <functional>
#include <assert.h>
#include <cmath>
#include <unordered_map>
#include <stack>

using namespace std;

using i64 = long long int;
using ii = pair<int, int>;
using ii64 = pair<i64, i64>;
using dd = pair<double, double>;

int main() {
	int n, m;
	cin >> n >> m;
	map<string, int> ss;
	for (int i = 0; i < n; ++i) {
		string s;
		cin >> s;
		ss[s]++;
	}
	int k;
	cin >> k;
	int ret = 0;
	for (auto s : ss) {
		int cnt = 0;
		for (auto c : s.first) {
			cnt += (c == '0');
		}
		if (cnt <= k && cnt % 2 == k % 2) {
			ret = max(ret, s.second);
		}
	}
	cout << ret;

	return 0;
}
