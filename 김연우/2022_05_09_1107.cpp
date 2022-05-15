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
	int notOK[10] = { 0, };
	int m;
	cin >> m;
	for (int i = 0; i < m; ++i) {
		int num;
		cin >> num;
		notOK[num] = true;
	}
	int ret = abs(n - 100);
	auto getCount = [&](int v) -> int {
		int count = 0;
		do {
			if (notOK[v % 10]) {
				return -1;
			}
			v /= 10;
			count++;
		} while (v > 0);
		return count;
	};
	for (int i = 0; i < 1000000; ++i) {
		int count = getCount(i);
		if (count != -1) {
			ret = min(ret, abs(n - i) + count);
		}
	}
	cout << ret;
	
	return 0;
}
