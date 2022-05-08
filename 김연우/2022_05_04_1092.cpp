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
	vector<int> ships(n, 0);
	for (auto& ship : ships) {
		cin >> ship;
	}
	int m;
	cin >> m;
	vector<int> goods(m, 0);
	for (auto& good : goods) {
		cin >> good;
	}
	sort(ships.begin(), ships.end());
	sort(goods.begin(), goods.end());
	if (goods[goods.size() - 1] > ships[ships.size() - 1]) {
		cout << -1;
		return 0;
	}
	int time = 0;
	while (goods.size() > 0) {
		for (auto ship : ships) {
			auto it = upper_bound(goods.begin(), goods.end(), ship);
			if (it == goods.begin()) {
				continue;
			}
			goods.erase(it - 1);
		}
		time++;
	}
	cout << time;
	return 0;
}
