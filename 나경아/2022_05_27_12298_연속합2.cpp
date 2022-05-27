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

#define X first;
#define Y second;

int N;
int mx = INT_MIN;
int A[100005];
int dp[100005][2];

int main() {

    cin >> N;
    for (int i=1; i<=N; i++) cin >> A[i];
    for (int i=0; i<100005; i++) {
        for (int j=0; j<2; j++) dp[i][j] = INT_MIN;
    }

    dp[1][1] = A[1];
    dp[2][0] = A[2];
    dp[2][1] = max(A[2], A[1]+A[2]);

    for (int i=3; i<=N; i++) {
        dp[i][1] = max(A[i], dp[i-1][1]+A[i]);
        dp[i][0] = max(dp[i-2][1]+A[i], dp[i-1][0]+A[i]);
    }

    for (int i=1; i<=N; i++) mx = max({mx, dp[i][0], dp[i][1]});
    cout<<mx;
    return 0;
}