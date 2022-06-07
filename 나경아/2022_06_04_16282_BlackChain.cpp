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

long long N, cnt;
long long P2[63];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    cin >> N;
    P2[0] = 1;
    for (int i=1; i<63; i++) P2[i] = P2[i-1]*2;

    cnt = 1;
    while ((cnt+1)*P2[cnt+1]-1 < N) cnt++;
    cout<<cnt;
    return 0;
}