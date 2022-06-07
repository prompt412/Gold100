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

string s, bomb;
stack<char> st;
vector<char> v;

void  popBomb() {

    stack<char> tmp;

    for (int i=bomb.size()-1; i>=0; i--) {
        if (st.top() == bomb[i]) {
            tmp.push(st.top());
            st.pop();
        }
        else break;
    }

    if (tmp.size() == bomb.size()) return ;
    while (!tmp.empty()) { st.push(tmp.top()); tmp.pop(); }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    cin >> s >> bomb;

    for (int i=0; i<s.size(); i++) {
        st.push(s[i]);
        if (s[i] != bomb[bomb.size()-1]) continue;
        if (st.size() < bomb.size()) continue;
        popBomb();
    }

    if (!st.size()) {
        cout<<"FRULA";
        return 0;
    }

    v.resize(st.size());
    int idx = st.size()-1;
    while (!st.empty()) {
        v[idx--] = st.top();
        st.pop();
    }

    for (auto x : v) cout<<x;
    return 0;
}