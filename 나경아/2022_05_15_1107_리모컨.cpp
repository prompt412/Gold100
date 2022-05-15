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

int N, M, x;
int mn = INT_MAX;
vector<bool> check(10, true);
vector<int> v(10, 0), p(10, 0);
vector<int> tmp;

void permutationWithRep(int k) {

    if (k >= 1) {
        int num = 0;
        for (int i=0; i<k; i++) num += p[k-1-i]*v[i];
        mn = min(mn, abs(num-N)+(int)to_string(num).length());
        if (k == 7) return ;
    }
    
    for (int i=0; i<10; i++) {
        if (!check[i]) continue;
        v[k] = i;
        permutationWithRep(k+1);
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    cin >> N >> M;
    while (M--) {
        cin >> x;
        check[x] = false;
    }

    p[0] = 1;
    for (int i=1; i<10; i++) p[i] = p[i-1]*10;

    mn = min(mn, abs(100-N));
    permutationWithRep(0);
    cout<<mn;
    return 0;
}