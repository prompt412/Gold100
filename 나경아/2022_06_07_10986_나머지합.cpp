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

long long N, M, ans;
long long A[1000005], s[1000005], cnt[1005];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    cin >> N >> M;
    for (int i=1; i<=N; i++) {
        cin >> A[i];
        s[i] = (s[i-1]+A[i])%M;
    }

    for (int i=0; i<=N; i++) cnt[s[i]]++;
    for (int i=0; i<M; i++) ans += cnt[i]*(cnt[i]-1)/2;
    
    cout<<ans;
    return 0;
}