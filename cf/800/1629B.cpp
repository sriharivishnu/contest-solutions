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
bool solve() {
    int l, r, k;
    cin >> l >> r >> k;

    if (l == r) return l != 1;
    if (l % 2 == 0) l++;
    return (r - l + 2) / 2 <= k;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        cout << (solve() ? "YES" : "NO") << endl;
    }
}
