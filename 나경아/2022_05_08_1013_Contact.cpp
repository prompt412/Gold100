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
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>
#include <string>
#include <sstream>
#include <iostream>
#include <regex>

using namespace std;
using ii = pair<int, int>;
using iii = tuple<int, int, int>;

#define X first
#define Y second

int N;
string str;

int main(){
    
    cin >> N;
    regex re("(100+1+|01)+");
    for(int i=0;i<N;i++){
        cin >> str;
        if(regex_match(str, re))
            cout << "YES" << endl;
        else cout << "NO" << endl;
    }
    return 0;
}