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

int m, n, num, cnt;
vector<int> v1, v2;

int main() {
	
	cin >> m;
	for (int i = 0; i < m; i++) {
		cin >> num;
		v1.push_back(num);
	}
	
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> num;
		v2.push_back(num);
	}
 
	sort(v1.begin(), v1.end(), greater<int>());
	sort(v2.begin(), v2.end(), greater<int>());
 
	if (v2[0] > v1[0]) {
        cout<<-1;
        return 0;
    }
    while (v2.size()) { 
        int index = 0; 
        for (int i = 0; i < v2.size(); i++) { 
            if (index == v1.size()) break;
            if (v1[index] >= v2[i]) {
                index++;
                v2.erase(v2.begin() + i); 
                i--;
            }
        }
        cnt++;
    }
    cout << cnt;
    return 0;
}