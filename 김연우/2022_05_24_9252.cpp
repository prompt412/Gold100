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

int table[1001][1001];
string s1, s2;

int solve(int a, int b) {
	if (a >= s1.length() || b >= s2.length()) {
		return 0;
	}
	auto& ret = table[a][b];
	if (ret == -1) {
		if (s1[a] == s2[b]) {
			ret = solve(a + 1, b + 1) + 1;
		}
		else {
			ret = max(solve(a, b + 1), solve(a + 1, b));
		}
	}
	return ret;
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	memset(table, -1, sizeof(table));
	cin >> s1 >> s2;
	int ret = solve(0, 0);
	int a = 0, b = 0;
	string out;
	while (a < s1.length() && b < s2.length()) {
		if (s1[a] == s2[b]) {
			out += s1[a];
			a += 1;
			b += 1;
			continue;
		}
		if (table[a][b + 1] > table[a + 1][b]) {
			b++;
		}
		else {
			a++;
		}
	}
	cout << ret << '\n' << out;
	return 0;
}
