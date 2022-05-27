#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <tuple>
#include <vector>
#include <stack>
#include <queue>
#include <deque>
#include <iostream>

using namespace std;
using ii = pair<int, int>;
using iii = tuple<int, int, int>;

#define X first
#define Y second

int N, M;
int dp[1005][1005];
int board[1005][1005];

int main() {

    while (true) {

        cin >> N >> M;
        if (N == 0 || M == 0) break;

        memset(dp, 0, sizeof(dp));
        memset(board, 0, sizeof(board));

        for (int i=1; i<=N; i++) {
            for (int j=1; j<=M; j++) cin >> board[i][j];
        }

        int mx = 0;
        for (int i=1; i<=N; i++) {
            for (int j=1; j<=M; j++) {
                if (!board[i][j]) continue;
                dp[i][j] = min({dp[i-1][j], dp[i][j-1], dp[i-1][j-1]})+1;
                mx = max(mx, dp[i][j]);
            }
        }

        cout<<mx<<"\n";
    }
    return 0;
}