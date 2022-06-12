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

#define X first
#define Y second

int N, M;
vector<ii> v;

int main() {

    cin >> N >> M;
    v.resize(N);
    for (int i=0; i<N; i++) cin >> v[i].X;
    for (int i=0; i<N; i++) cin >> v[i].Y;
    sort(v.begin(), v.end());

    int cnt = 0;
    int idx = 1;
    int poss = v[0].X+v[0].Y;

    while (poss < M && idx < N && v[idx].X <= poss) {
        int mx = 0;
        while (idx < N && v[idx].X <= poss) {
            mx = max(mx, v[idx].X+v[idx].Y);
            idx++;
        }
        if (mx < poss) break;
        poss = mx;
        cnt++;
    }

    if (poss >= M) cout<<cnt;
    else cout<<-1;
    return 0;
}