#include <assert.h>

#include <algorithm>
#include <cmath>
#include <iostream>
#include <limits>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

typedef long long ll;

typedef vector<int> vi;
typedef pair<int, int> pii;
typedef vector<std::pair<int, int>> vii;
typedef vector<vector<int>> vvi;

// IMPLEMENTATION
void solve() {
    int a = 0, b = 0, c = 0;

    string s;
    cin >> s;
    for (int i = 0; i < s.size(); ++i) a += (s[i] == '1');
    for (int i = 0; i < s.size(); ++i) b += (s[i] == '2');
    for (int i = 0; i < s.size(); ++i) c += (s[i] == '3');

    for (int i = 0; i < s.size(); i += 2) {
        if (a)
            s[i] = '1', --a;
        else if (b)
            s[i] = '2', --b;
        else
            s[i] = '3', --c;
    }
    cout << s << endl;
}

int main() { solve(); }
