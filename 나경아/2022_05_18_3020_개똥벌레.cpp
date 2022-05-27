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

int N, H, x, sum, cnt;
vector<ii> v;
vector<int> res; 

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    cin >> N >> H;
    for (int i=0; i<N; i++) {
        cin >> x;
        if (i%2 == 0) v.push_back({H-x, +1});
        else {
            v.push_back({0, +1});
            v.push_back({x, -1});
        }
    }
    sort(v.begin(), v.end());

    int j = 0;
    for (int i=0; i<H; i++) {
        while (j < v.size() && v[j].X <= i) sum += v[j++].Y;
        res.push_back(sum);
    }
    sort(res.begin(), res.end());

    cout<<res[0]<<" ";
    for (int i=0; i<res.size(); i++) {
        if (res[i] != res[0]) break;
        cnt++;
    }
    cout<<cnt<<" ";
    return 0;
}