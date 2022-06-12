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
#include <climits>
#include <iostream>

using namespace std;
using ii = pair<int, int>;
using iii = tuple<int, int, int>;
using vi = vector<int>;
using vvi = vector<vector<int>>;

#define X first
#define Y second

int N, M;
int ncard[100005];

bool check() {

    vi cnt(100005, 0);

    for (int i=1; i<=N; i++)
        cnt[ncard[i]]++;

    for (int i=1; i<=N; i++) {
        if (cnt[i] != 1) return false;
    }
    return true;
}

int main() {

    cin >> N >> M;
    for (int i=1; i<=N; i++) ncard[i] = i;

    while (M--) {
        int x, y;
        cin >> x >> y;
        ncard[x]++;
        ncard[y]--;
    }

    if (!check()) {
        cout<<-1;
        return 0;
    }
    
    for (int i=1; i<=N; i++) cout<<ncard[i]<<" ";
    return 0;
}