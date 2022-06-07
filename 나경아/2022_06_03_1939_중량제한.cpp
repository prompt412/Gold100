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
using iii = tuple<int, int>;

#define X first
#define Y second

int N, M, mx, st, en;
vector<vector<ii>> graph(10005, vector<ii>(0));

bool bfs(int w) {
    
    queue<int> q;
    vector<bool> visited(10005, false);
    
    q.push(st);
    visited[st] = true;

    while (!q.empty()) {

        int cur = q.front();
        if (cur == en) return true;
        q.pop();

        for (auto [node, lim] : graph[cur]) {
            if (visited[node] || lim < w) continue;
            visited[node] = true;
            q.push(node);
        }
    }
    return false;
}

int binarySearch() {

    int first = 1;
    int last = mx;
    int ret = 1;

    while (first <= last) {
        int mid = (first+last)/2;
        if (bfs(mid)) {
            first = mid+1;
            ret = mid;
        }
        else last = mid-1;
    }
    return ret;
}

int main() {

    cin >> N >> M;
    while (M--) {
        int A, B, C;
        cin >> A >> B >> C;
        graph[A].push_back({B, C});
        graph[B].push_back({A, C});
        mx = max(mx, C);
    }
    cin >> st >> en;
    cout<<binarySearch();
    return 0;
}