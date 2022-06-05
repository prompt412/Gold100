#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <tuple>
#include <vector>
#include <queue>
#include <deque>
#include <set>
#include <map>
#include <iostream>

using namespace std;
using ii = pair<int, int>;
using iii = tuple<int, int, int>;

#define X first
#define Y second

int N;
vector<int> vsum, vdiff;

int main() {

    cin >> N;
    for (int i=0; i<N; i++) {
        int a, b;
        cin >> a >> b;
        vsum.push_back(a+b);
        vdiff.push_back(a-b);
    }

    sort(vsum.begin(), vsum.end());
    sort(vdiff.begin(), vdiff.end());
    cout<<max(vsum[N-1]-vsum[0], vdiff[N-1]-vdiff[0]);
    return 0;
}