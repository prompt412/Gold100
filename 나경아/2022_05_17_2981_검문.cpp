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
using iii = tuple<int, int, int>;

#define X first
#define Y second

int N, g;
vector<int> v, res;

int gcd(int a, int b) {
    if (b == 0) return a;
    return gcd(b, a%b);
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    cin >> N; v.resize(N);
    for (int i=0; i<N; i++) cin >> v[i];
    sort(v.begin(), v.end());

    g = v[1]-v[0];
    for (int i=2; i<N; i++)
        g = gcd(g, v[i]-v[i-1]);

    for (int i=2; i*i<=g; i++) {
        if (!(g%i)) res.push_back(i);
    }

    for (int i=res.size()-1; i>=0; i--) {
        if (res[i] != g/res[i]) res.push_back(g/res[i]);
    }
    res.push_back(g);

    for (auto x : res) cout<<x<<" ";
    return 0;
}