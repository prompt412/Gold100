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
	int N;
	cin >> N;
	vector<i64> nums(N, 0);
	for (auto& num : nums) {
		cin >> num;
	}
	i64 v = 9876543210;
	ii64 ans;
	auto check = [&](i64 newV, i64 num) {
		if (newV == num || abs(v) <= abs(num + newV)) {
			return;
		}
		v = num + newV;
		ans.first = min(num, newV);
		ans.second = max(num, newV);
	};
	for (int i = 0; i < N; ++i) {
		i64 num = nums[i];
		auto it = lower_bound(nums.begin() + i, nums.end(), -num);
		if (it != nums.end()) {
			check(*it, num);
		}
		if (it != nums.begin()) {
			check(*(it - 1), num);
		}
	}
	cout << ans.first << ' '  << ans.second;

	return 0;
}
