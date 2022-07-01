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
using ic = pair<int, char>;
using iii = tuple<int, int, int>;

#define X first
#define Y second

int N;
ii st, en;
int dist[654325][100];
vector<ii> v(10);

ii conv(const vector<ii>& v) {

  ii p;
  for (int i=0; i<N; i++) {
    p.X = p.X*10+v[i].X;
    p.Y = p.Y*2+v[i].Y;
  }
  return p;
}

int bfs() {

    for (int i=0; i<654325; i++) {
        for (int j=0; j<100; j++) dist[i][j] = -1;
    }

    queue<ii> q;
    q.push(st);
    dist[st.X][st.Y] = 0;

    while (!q.empty()) {

        ii cur = q.front();
        if (cur.X == en.X && cur.Y == en.Y) return dist[cur.X][cur.Y];
        q.pop();

        ii tmp = cur;
        vector<ii> vec(N);
        for (int i=N-1; i>=0; i--) {
            vec[i].X = tmp.X%10;
            vec[i].Y = tmp.Y%2;
            tmp.X /= 10;
            tmp.Y /= 2;
        }

        for (int i=1; i<=N; i++) {
            vector<ii> cpy = vec;
            reverse(cpy.begin(), cpy.begin()+i);
            for (int j=0; j<i; j++) cpy[j].Y = abs(cpy[j].Y-1);
            ii newp = conv(cpy);
            if (dist[newp.X][newp.Y] != -1) continue;
            q.push(newp);
            dist[newp.X][newp.Y] = dist[cur.X][cur.Y]+1;
        }
    }
    return -1;
 }

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    cin >> N;
    for (int i=0; i<N; i++) {
        cin >> v[i].X;
        char c;
        cin >> c;
        if (c == '+') v[i].Y = 1;
        else v[i].Y = 0;
    }

    st = conv(v);
    for (int i=0; i<N; i++) {
        en.X = en.X*10+(i+1);
        en.Y = en.Y*2+1;
    }
    
    cout<<bfs();
    return 0;
}