#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <tuple>
#include <vector>
#include <stack>
#include <queue>
#include <deque>
#include <set>
#include <map>
#include <iostream>

using namespace std;
using ii = pair<int, int>;
using iii = tuple<int, int>;

int N, i, s, e, re, mx;
vector<ii> v;

int main() {

    cin >> N;
    while (N--) {
        cin >> i >> s >> e;
        v.push_back({s, 1});
        v.push_back({e, -1});
    }

    sort(v.begin(), v.end());

    for (auto [x, y] : v) {
        re += y;
        mx = max(mx, re);
    }
    cout<<mx;
    return 0;
}