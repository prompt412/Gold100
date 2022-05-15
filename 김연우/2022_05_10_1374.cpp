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
	int n;
	cin >> n;
	vector<ii> vs;
	for (int i = 0; i < n; ++i) {
		int n, s, e;
		cin >> n >> s >> e;
		vs.emplace_back(s, 1);
		vs.emplace_back(e, -1);
	}
	sort(vs.begin(), vs.end());

	i64 now = 0;
	i64 maxV = 0;
	for (auto v : vs) {
		now += v.second;
		maxV = max(maxV, now);
	}
	cout << maxV;

	return 0;
}
