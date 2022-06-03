#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <tuple>
#include <vector>
#include <stack>
#include <queue>
#include <deque>
#include <climits>
#include <iostream>

using namespace std;
using ii = pair<int, int>;
using iii = tuple<int, int, int>;

#define X first
#define Y second
#define div 987654321

long long N = 0, ret = 1;
bool check[1000005];

void eratos() {

    for (long long i=2; i*i<=N; i++) {
        if (check[i]) continue;
        for (long long j=i*i; j<=N; j+=i) 
            check[j] = true;
    }
}

void getAns() {

    for (long long i=2; i<=N; i++) {
        if (check[i]) continue;
        long long tmp = i;
        while (tmp*i <= N) {
            tmp *= i;
        }
        ret = (ret*tmp)%div;
    }
}

int main() {

    cin >> N;
    eratos();
    getAns();
    cout<<ret;
    return 0;
}