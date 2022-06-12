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
using vi = vector<int>;
using di = deque<int>;
using vvi = vector<vector<int>>;

#define X first
#define Y second

int N;
vi vpos, vneg;
di dpos, dneg;

void rearrange(vi& v, di& d) {

    for (int i=0; i<v.size(); i++) {
        if (i%2 == 0) d.push_front(v[i]);
        else d.push_back(v[i]);
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    cin >> N;
    for (int i=0; i<N; i++) {
        int x;
        cin >> x;
        if (x > 0) vpos.push_back(x);
        else vneg.push_back(x);
    }

    sort(vpos.begin(), vpos.end(), greater<>());
    sort(vneg.begin(), vneg.end());

    rearrange(vpos, dpos);
    rearrange(vneg, dneg);

    if (!dpos.empty() && dpos.front() < dpos.back()) reverse(dpos.begin(), dpos.end());
    if (!dneg.empty() && dneg.front() < dneg.back()) reverse(dneg.begin(), dneg.end());
    
    for (auto x : dpos) cout<<x<<" ";
    for (auto x : dneg) cout<<x<<" ";
    return 0;
}