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
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	i64 n;
	cin >> n;
	stack<ii64> buildings;
	i64 cnt = 0;
	for (i64 i = 0; i < n; ++i) {
		i64 b;
		cin >> b;
		while (!buildings.empty() && buildings.top().first <= b) {
			int prev = buildings.top().second;
			cnt += (i - prev - 1);
			buildings.pop();
		}
 		buildings.emplace(b, i);
	}
	while (!buildings.empty()) {
		i64 prev = buildings.top().second;
		cnt += (n - prev - 1);
		buildings.pop();
	}
	cout << cnt;

	return 0;
}
