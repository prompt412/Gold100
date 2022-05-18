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

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	while (true) {
		int n, m;
		cin >> n >> m;
		if (n == 0 && m == 0) {
			break;
		}
		int maxV = 0;
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < m; ++j) {
				cin >> table[i][j];
				maxV = max(maxV, table[i][j]);
			}
		}

		for (int i = 1; i < n; ++i) {
			for (int j = 1; j < m; ++j) {
				if (table[i][j] == 0) {
					continue;
				}
				table[i][j] = min({ table[i - 1][j - 1], table[i][j - 1], table[i - 1][j] }) + 1;
				maxV = max(maxV, table[i][j]);
			}
		}
		cout << maxV << '\n';
	}

	return 0;
}
