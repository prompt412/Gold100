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

#define X first;
#define Y second;

string s;

bool isAllSame() {

    for (int i=1; i<s.size(); i++) {
        if (s[i-1] == s[i]) continue;
        return false;
    }
    return true;
}

bool isPalindrome() {

    for (int i=0; i<s.size()/2; i++) {
        if (s[i] != s[(int)s.size()-1-i]) 
            return false;        
    }
    return true;
}

int main() {

    cin >> s;

    if (isAllSame()) cout<<-1;
    else if (!isPalindrome()) cout<<s.size();
    else cout<<s.size()-1;
    return 0;
}