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

#define X first
#define Y second

int N, M, O, P, Q;
int parent[100005];
int np[100005];
vector<int> v;

int find(int u) {
    if (parent[u] == u) return u;
    return parent[u] = find(parent[u]);
}

void merge(int u, int v) {

    u = find(u);
    v = find(v);

    if (np[u] > np[v]) swap(u, v);
    parent[u] = v;
    np[v] += np[u];
}

void fight(int u, int v) {

    u = find(u);
    v = find(v);

    if (np[u] == np[v]) {
        parent[u] = -1;
        parent[v] = -1;
        return;
    }

    if (np[u] > np[v]) swap(u, v);
    parent[u] = v;
    np[v] -= np[u];
}

int main() {

    cin >> N >> M;
    for (int i=1; i<=N; i++) {
        parent[i] = i;
        cin >> np[i];
    }

    while (M--) {
        cin >> O >> P >> Q;
        if (O == 1) merge(P, Q);
        else fight(P, Q);
    }

    for (int i=1; i<=N; i++) {
        if (find(i) == i) v.push_back(np[i]);
    }

    sort(v.begin(), v.end());
    cout<<v.size()<<"\n";
    for (auto x : v) cout<<x<<" ";
    return 0;
}