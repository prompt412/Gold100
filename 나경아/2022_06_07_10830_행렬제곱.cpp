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
using vvi = vector<vector<int>>;

#define X first
#define Y second
#define div 1000

int N;
long long B;
vvi A(10, vi(10, 0));

vvi mult(const vvi& v1, const vvi& v2) {

    vvi v(N, vi(N, 0));
    
    for (int i=0; i<N; i++) {
        for (int j=0; j<N; j++) {
            for (int l=0; l<N; l++)
                v[i][j] = (v[i][j]+v1[i][l]*v2[l][j]%div)%div;
        }
    }
    return v;
}

vvi powMatrix(long long k) {

    if (k == 1) {
        vvi ret(N, vi(N, 0));
        for (int i=0; i<N; i++) {
            for (int j=0; j<N; j++) 
                ret[i][j] = A[i][j]%div;
        }
        return ret;
    }

    vvi splited = powMatrix(k/2);
    if (k%2 == 0) return mult(splited, splited);
    return mult(mult(splited, splited), A);
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    cin >> N >> B;
    for (int i=0; i<N; i++) {
        for (int j=0; j<N; j++) 
            cin >> A[i][j];
    }

    for (auto& row : powMatrix(B)) {
        for (auto& col : row) cout<<col<<" ";
        cout<<"\n";
    }
    return 0;
}