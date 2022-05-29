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

using namespace std;

using i64 = long long int;
using ii = pair<int, int>;
using ii64 = pair<i64, i64>;

int main() {
	int x1, y1, x2, y2, x3, y3;
	cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
	ii v1 = { x2 - x1, y2 - y1 };
	ii diagonalV1 = { -v1.second, v1.first };
	ii v2 = { x3 - x2, y3 - y2 };
	int dotProduct = diagonalV1.first * v2.first + diagonalV1.second * v2.second;
	int sign = (dotProduct > 0) - (dotProduct < 0);
	cout << sign;
	return 0;
}