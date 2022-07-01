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

int N, re;
int board[50][50];
bool visited[50][50];

int dir[3][2][3] = {
    {{0, 0, 0}, {0, 0, 0}},
    {{-1, 1, 1}, {0, -1, 1}},
    {{-1, -1, 1}, {-1, 1, 0}}
};

bool OOB(int x, int y) {
    return x < 0 || x >=50 || y < 0 || y >= 50;
}

void dfs(int x, int y, int bx, int by, int cnt) {
    
    if (cnt == N) return ;
    visited[x][y] = true;

    for (int i=0; i<3; i++) {
        int n = board[x][y];
        int nx = x+dir[n][0][i];
        int ny = y+dir[n][1][i];
        if (nx == bx && ny == by) continue;
        if (visited[nx][ny] && cnt == N-1) re++;
        if (OOB(nx, ny) || !board[nx][ny] || visited[nx][ny]) continue;
        dfs(nx, ny, x, y, cnt+1);
    }

    visited[x][y] = false;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    
    cin >> N;
    if (N < 5) {
        cout<<0;
        return 0;
    }

    for (int i=0; i<50; i++) {
        for (int j=0; j<50; j++) {
            int r = i%4, c = j%4;
            if (r == 0 && (c == 1 || c == 3)) board[i][j] = 1;
            else if (r == 1 && (c == 0 || c == 2)) board[i][j] = 2;
            else if (r == 2 && (c == 0 || c == 2)) board[i][j] = 1;
            else if (r == 3 && (c == 1 || c == 3)) board[i][j] = 2;
        }
    }

    visited[24][25] = true;
    dfs(23, 25, -1, -1, 0);
    cout<<re;
    return 0;
}