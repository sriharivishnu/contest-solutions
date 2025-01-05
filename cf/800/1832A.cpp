#include <assert.h>

#include <algorithm>
#include <cmath>
#include <iostream>
#include <limits>
#include <map>
#include <numeric>
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
bool solve() {
    string s;
    cin >> s;

    for (int i = 1; i < s.size() / 2; ++i) {
        if (s[i] != s[i - 1]) return true;
    }
    return false;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        cout << (solve() ? "YES" : "NO") << endl;
    }
}
