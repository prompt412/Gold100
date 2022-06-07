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
#define INF INT_MAX/2;

int N;
int s[5005];
int dp[5005][5005];

int main() {

    cin >> N;
    for (int i=1; i<=N; i++) cin >> s[i];
    
    for (int i=0; i<5005; i++) {
        for (int j=0; j<5005; j++) 
            dp[i][j] = INF;
    }

    for (int l=1; l<=N; l++) {
        for (int st=1; st<=N; st++) {
            int en = st+l-1;
            if (en > N) continue;
            if (l == 1) {
                dp[st][en] = 0;
                continue;
            }
            else if (l == 2) {
                if (s[st] == s[en]) dp[st][en] = 0;
                else dp[st][en] = 1;
                continue;
            }
            
            if (s[st] == s[en]) dp[st][en] = dp[st+1][en-1];
            else dp[st][en] = min(dp[st+1][en], dp[st][en-1])+1;
        }
    }

    cout<<dp[1][N];
    return 0;
}