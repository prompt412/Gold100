#include <cstdio>
#include <cstring>
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

int n, m;
int p[1000005];
int nrank[1000005];

void initialize() {
    
    for (int i=0; i<=n; i++) {
        p[i] = i;
        nrank[i] = 1;
    }    
}

int find(int u) {

    if (p[u] == u) return u;
    return p[u] = find(p[u]);
}

void merge(int u, int v) {

    u = find(u);
    v = find(v);

    if (u == v) return ;
    if (nrank[u] > nrank[v]) swap(u, v);
    p[u] = v;
    if (nrank[u] == nrank[v]) nrank[v]++;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    cin >> n >> m;
    initialize();

    while (m--) {
        int o, a, b;
        cin >> o >> a >> b;
        if (o == 0) merge(a, b);
        else if (find(a) == find(b)) cout<<"YES"<<"\n";
        else cout<<"NO"<<"\n";
    }
    return 0;
}