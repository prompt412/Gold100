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
#define clock -1
#define anticlock 1
#define line 0

int main() {

    int x1, x2, x3, y1, y2, y3;
    cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;

    int left = (y2-y1)*x3*(abs(x2-x1)/(x2-x1))+y1*abs(x2-x1)-(y2-y1)*x1*(abs(x2-x1)/(x2-x1));
    int right = y3*abs(x2-x1);

    if (left == right) cout<<line;
    else if ((y2-y1)*(x2-x1) >= 0) { //기울기 양수
        if (x1 <= x2) {
            if (left > right) cout<<clock;
            else cout<<anticlock;
        }
        else {
            if (left > right) cout<<anticlock;
            else cout<<clock;
        }

    }
    else { //기울기 음수
        if (x1 <= x2) {
            if (left > right) cout<<clock;
            else cout<<anticlock;
        }
        else {
            if (left > right) cout<<anticlock;
            else cout<<clock;
        }
    }
    return 0;
}