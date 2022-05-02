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

const string as = "100-1+";
const string bs = "01";

int table[201][6][2];

bool solve(const string& input, int cursor, int a, int b) {
	if (cursor == input.length()) {
		if ((a == 0 && b == 0) || (a == as.length() -1 && b == 0)) {
			return true;
		}
		return false;
	}
	auto& ret = table[cursor][a][b];
	if (ret != -1) {
		return ret;
	}
	char now = input[cursor];
	if (a == 0 && b == 0) {
		if (now == '1') {
			return ret = solve(input, cursor + 1, 1, 0);
		}
		return ret = solve(input, cursor + 1, 0, 1);
	}
	if (a > 0) {
		if (as[a] == '-') {
			if (now == '1') {
				return ret = solve(input, cursor + 1, a + 2, 0);
			}
			return ret = solve(input, cursor + 1, a, 0);
		}
		if (as[a] == '+') {
			if (now == '0') {
				return ret = solve(input, cursor + 1, 0, 1);
			}
			return ret = solve(input, cursor + 1, a, 0) || solve(input, cursor + 1, 1, 0);
		}
		if (as[a] != now) {
			return ret = false;
		}
		return ret = solve(input, cursor + 1, a + 1, 0);
	}
	if (b > 0) {
		if (bs[b] != now) {
			return ret = false;
		}
		return ret = solve(input, cursor + 1, 0, 0);
	}
	return ret = false;
}

int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; ++i) {
		memset(table, -1, sizeof(table));
		string s;
		cin >> s;
		cout << (solve(s, 0, 0, 0) ? "YES" : "NO") << '\n';
	}

	return 0;
}
