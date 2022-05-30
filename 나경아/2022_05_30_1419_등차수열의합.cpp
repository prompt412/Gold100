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
#include <climits>
#include <iostream>

using namespace std;
using ii = pair<int, int>;
using iii = tuple<int, int, int>;

#define X first;
#define Y second;

int l, r, k, ret;

int main() {

    cin >> l >> r >> k;
    if (k == 2) {
        if (r < 3) ret = 0;
        else ret = min({r-3+1, r-l+1});
    }
    else if (k == 3) {
        for (int i=6; i<=r; i+=3) {
            if (i >= l) ret++;
        }
    }
    else if (k == 4) {
        for (int i=10; i<=r; i+=2) {
            if (i != 12 && i >= l) ret++;
        }
    }
    else {
        for (int i=15; i<=r; i+=5) {
            if (i >= l) ret++;
        }
    }
    cout<<ret;
    return 0;
}