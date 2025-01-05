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
    string s;
    cin >> s;
    int lc = 0, n = s.size();
    for (int i = 0; i < n; ++i) lc += !!islower(s[i]);
    if (lc >= n - lc) {
        for (int i = 0; i < n; ++i) s[i] = tolower(s[i]);
    } else {
        for (int i = 0; i < n; ++i) s[i] = toupper(s[i]);
    }
    cout << s << endl;
}

int main() { solve(); }
